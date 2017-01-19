/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:36:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/19 16:56:58 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(int keycode, t_env *env)
{
	if (keycode == KEY_UP)
	{
		if (env->space < 1024)
			env->space = env->space * 2;
		display_img(*env, 0);
	}
	if (keycode == KEY_DOWN)
	{
		if (env->space > SPACE)
			env->space = env->space / 2;
		display_img(*env, 0);
	}
}

void	move_vertical(int keycode, t_env *env)
{
	if (keycode == KEY_W)
	{
		env->ory -= 10;
		display_img(*env, 0);
	}
	if (keycode == KEY_S)
	{
		env->ory += 10;
		display_img(*env, 0);
	}
}

void	move_horizontal(int keycode, t_env *env)
{
	if (keycode == KEY_A)
	{
		env->orx -= 10;
		display_img(*env, 0);
	}
	if (keycode == KEY_D)
	{
		env->orx += 10;
		display_img(*env, 0);
	}
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		scale(keycode, env);
	if (keycode == KEY_W || keycode == KEY_S)
		move_vertical(keycode, env);
	if (keycode == KEY_A || keycode == KEY_D)
		move_horizontal(keycode, env);
	return (0);
}
