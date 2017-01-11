/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/11 19:15:37 by vafanass         ###   ########.fr       */
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

void	display_window(t_env env)
{
	if (!(env.mlx = mlx_init()))
		error(ERRMLX);
	if (!(env.win = mlx_new_window(env.mlx, 1280, 720, "coucou")))
		error(ERRMLX);
	mlx_key_hook(env.win, end_all, 0);
	mlx_loop(env.mlx);
	return ;
}
