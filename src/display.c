/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/14 19:22:17 by vafanass         ###   ########.fr       */
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
void	display_img(t_env env)
{
	int kek;
	int i;
	int xtest;
	double alpha;
	double beta;
	int	x1;
	int y1;
	kek = 0;
	
	alpha = M_PI/180 * 30;
	beta =  M_PI/180 * 30;
	
	printf("alpha = %f beta = %f\n", alpha, beta);
	if(!(env.img_ptr = mlx_new_image(env.mlx, SCREEN_X, SCREEN_Y)))
		error(ERRMLX);
	env.img = mlx_get_data_addr(env.img_ptr, &env.img_bpp, &env.img_size, 
			&env.img_endian);
	while (kek < env.size)
	{
		//x1 = (env.map[kek].x - env.map[kek].y) * cos(0.46365);
		//y1 = env.map[kek].y + ((env.map[kek].x + env.map[kek].z) * sin(0.46365));

		x1 = (env.map[kek].x * cos(alpha)) - (env.map[kek].y * cos(beta));
		y1 = (-env.map[kek].z + 10)  + (env.map[kek].x * sin(alpha)) + (env.map[kek].y * cos(beta));
		
		x1 = x1 * env.space;
		y1 = y1 * env.space;
		env.color = hex_to_rgb(env.map[kek].color);
		xtest = (x1 + 920) * 4 + (y1 + 100) * env.img_size;
		put_pixel(xtest, env);
		kek++;
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
