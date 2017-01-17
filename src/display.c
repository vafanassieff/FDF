/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/17 14:00:24 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void line_bis(t_line l, t_env env)
{
	while(l.x <= l.vx)
	{
		if (l.steep)
		{
			l.xfinal = (l.x + 500) * 4 + (l.y + 300) * env.img_size;
			if (l.xfinal < env.img_size * SCREEN_Y)
				put_pixel(l.xfinal, env);
		}
		else
		{
			l.xfinal = (l.y + 500) * 4 + (l.x + 300) * env.img_size;
			if (l.xfinal < env.img_size * SCREEN_Y)
				put_pixel(l.xfinal, env);
		}
		l.error += l.derror;
		if (l.error > l.dx)
		{
			if (l.vy > l.uy)
				l.y++;
			else
				l.y--;
			l.error -= l.dx * 2;
		}
		l.x++;
	}
}

void line(t_coord u, t_coord v, t_env env)
{
	t_line l;

	l.steep = 1;
	if (ft_abs(u.x - v.x) < ft_abs(u.y - v.y)) 
	{ 
		ft_swap(&u.x, &u.y); 
		ft_swap(&v.x, &v.y); 
		l.steep = 0; 
	} 
	if (u.x > v.x) 
	{ 
		ft_swap(&u.x, &v.x); 
		ft_swap(&u.y, &v.y); 
	} 
	l.dx = v.x - u.x; 
	l.dy = v.y - u.y; 
	l.derror = ft_abs(l.dy) * 2; 
	l.error = 0;
	l.y = u.y;
	l.x = u.x;
	l.vx = v.x;
	l.vy = v.y;
	l.uy = u .y;
	line_bis(l, env);
} 

void	display_img(t_env env)
{
	int count;
	int i;
	t_coord *c;

	count = 0;
	if(!(c = malloc(sizeof(t_coord) * 3)))
		error(ERRALLOC);
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
			line(c[0], c[1], env);
		if (env.map[count].y < env.width - 1)
			line(c[0], c[2], env);
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
