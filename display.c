/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/12 18:14:02 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	end_all(int keycode, void *param)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	printf("key event = %d\n", keycode);
	return ((int)param);
}



t_point	*map_to_iso(t_env env)
{
	int i;
	int c1;
	int c2;

	c1 = 1;
	c2 = 1;
	
	i = 0;
	if (!(env.coord = malloc(sizeof(t_point) * env.size)))
		error(ERRALLOC);
	//env.coord = env.map;
	//while (i < env.size)
	//{



	while (i < env.size)
	{
		env.coord[i].x = (env.map[i].x - env.map[i].y) / env.map[i].z * 64;
		env.coord[i].y = (env.map[i].x + env.map[i].y) / env.map[i].z * 32;
		env.coord[i].z = 0;
		env.coord[i].color = 0x00FFFFFF;
		i++;
	}
	return (env.coord);
}


void	display_window(t_env env)
{
	if (!(env.mlx = mlx_init()))
		error(ERRMLX);
	if (!(env.win = mlx_new_window(env.mlx, 1280, 720, env.name)))
		error(ERRMLX);
	
	env.coord = map_to_iso(env);
	int i;
	i = 0;
	while (i < env.size)
	{
		mlx_pixel_put( env.mlx, env.win, env.coord[i].x + 1280/2 , env.coord[i].y ,0x00FFCCCC);
		i++;
	}
	mlx_key_hook(env.win, end_all, 0);
	mlx_loop(env.mlx);
	return ;
}
