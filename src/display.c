/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/13 18:38:23 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	if (keycode == 126)
		((t_env*)env)->space = 32;
	printf("key event = %d\n", keycode);
	return (0);
}

t_color	hex_to_rgb(int color)
{
	t_color	ret;

	ret.r = color & 0xff;
	ret.g = (color>>8) & 0xff;
	ret.b = (color>>16) & 0xff;

	return (ret);
}

void	display_window(t_env env)
{
	int i;
	int	j;
	int bpp;
	int size;
	int endian;
	int kek;
	int xtest;

	kek = 0;
	if (!(env.mlx = mlx_init()))
		error(ERRMLX);
	if (!(env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, env.name)))
		error(ERRMLX);
	env.img_ptr = mlx_new_image(env.mlx, SCREEN_X, SCREEN_Y);
	env.img = mlx_get_data_addr(env.img_ptr, &bpp, &size, &endian);
	env.space = 16;
	
	while (kek < env.size)	
	{	
		env.color = hex_to_rgb(env.map[kek].color);
		xtest = env.map[kek].x * 4 + env.map[kek].y * size;
		xtest = xtest * env.space;
		ft_memset(&env.img[800 + size * 64 + xtest], env.color.b, 1);
		ft_memset(&env.img[801 + size * 64 + xtest], env.color.g, 1);
		ft_memset(&env.img[802 + size * 64 + xtest], env.color.r, 1);
		kek++;
	}
	printf("env.space = %d\n", env.space);

	i = mlx_put_image_to_window(env.mlx, env.win,env.img_ptr, 0, 0);
	j = mlx_destroy_image (env.mlx, env.img_ptr);

	mlx_key_hook(env.win, key_hook, &env);
	printf("env.space = %d\n", env.space);
	mlx_loop(env.mlx);
	return ;
}
