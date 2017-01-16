/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/16 17:03:02 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	hex_to_rgb(int color)
{
	t_color	ret;

	ret.r = color & 0xff;
	ret.g = (color>>8) & 0xff;
	ret.b = (color>>16) & 0xff;

	return (ret);
}
void	put_pixel(int xtest, t_env env)
{
	ft_memset(&env.img[0 + xtest], env.color.b, 1);
	ft_memset(&env.img[1 + xtest], env.color.g, 1);
	ft_memset(&env.img[2 + xtest], env.color.r, 1);
}

void line(int x0, int y0, int x1, int y1, t_env env) 
//void line(t_coord u, t_coord v, t_env env)
{
	t_line l;

	l.steep = 1;

	if (ft_abs(x0-x1) < ft_abs(y0-y1)) 
	{ 
		ft_swap(&x0, &y0); 
		ft_swap(&x1, &y1); 
		l.steep = 0; 
	} 
	if (x0>x1) 
	{ 
		ft_swap(&x0, &x1); 
		ft_swap(&y0, &y1); 
	} 
	l.dx = x1-x0; 
	l.dy = y1-y0; 
	l.derror = ft_abs(l.dy)*2; 
	l.error = 0; 
	l.y = y0; 
	for (l.x=x0; l.x<=x1; l.x++) 
	{
		if (l.steep) 
		{
			l.xfinal = (l.x + 500) * 4 + (l.y + 300) * env.img_size;
			put_pixel(l.xfinal, env);
		} 
		else 
		{ 
			l.xfinal = (l.y + 500) * 4 + (l.x + 300) * env.img_size;
			put_pixel(l.xfinal, env);
		} 
		l.error += l.derror; 
		if (l.error > l.dx) 
		{ 
			l.y += (y1>y0?1:-1); 
			l.error -= l.dx*2; 
		} 
	} 
} 

t_coord space_to_iso(t_point here, t_env env)
{
	t_coord	coord;
	double	alpha;
	double	beta;

	alpha = M_PI/180 * 0;
	beta =  M_PI/180 * 0;

	coord.x = (here.x * cos(alpha)) - (here.y * cos(beta));
	coord.y = (-here.z)  + (here.x * sin(alpha)) + (here.y * cos(beta));

	coord.x = coord.x * env.space;
	coord.y = coord.y * env.space;
	return (coord);
}

void	display_img(t_env env)
{
	int count;
	int i;
	t_coord *c;
	count = 0;
	c = malloc(sizeof(t_coord) * 3);
	if(!(env.img_ptr = mlx_new_image(env.mlx, SCREEN_X, SCREEN_Y)))
		error(ERRMLX);
	env.img = mlx_get_data_addr(env.img_ptr, &env.img_bpp, &env.img_size, 
			&env.img_endian);
	while (count < env.size)
	{
		env.color = hex_to_rgb(env.map[count].color);
		c[0] = space_to_iso(env.map[count], env);
		if (count + 1 < env.size)
			c[1] = space_to_iso(env.map[count + 1], env);
		if (count + env.length < env.size)
			c[2] = space_to_iso(env.map[count + env.length], env);
		if (env.map[count].x < env.length - 1)
			line(c[0].x , c[0].y, c[1].x, c[1].y, env);
		if (env.map[count].y < env.width - 1)
			line(c[0].x, c[0].y, c[2].x, c[2].y, env);
		count++;
	}
	i = mlx_put_image_to_window(env.mlx, env.win,env.img_ptr, 0, 0);
}
void	display_window(t_env env)
{
	if (!(env.mlx = mlx_init()))
		error(ERRMLX);
	if (!(env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, env.name)))
		error(ERRMLX);
	env.space = SPACE;
	display_img(env);

	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return ;
}
