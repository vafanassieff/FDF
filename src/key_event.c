/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:36:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/17 19:00:49 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_plus(t_env *env)
{
	env->space = env->space * 2;
	display_img(*env, 0);
}

void	scale_minus(t_env *env)
{

	if (env->space > SPACE)
		env->space = env->space / 2;
		else 
		return ;

	display_img(*env, 0);
}
void	increase(t_env *env)
{
	int count;

	count = 0;
	while (count < env->size)
	{
		if (env->map[count].z > 1 || env->map[count].z < -1)
			env->map[count].z += 1;
		count++;
	}
	display_img(*env, 0);
}
void	decrease(t_env *env)
{
	int count;

	count = 0;
	while (count < env->size)
	{
		if (env->map[count].z > 1 || env->map[count].z < -1)
			env->map[count].z += -1;
		count++;
	}
	display_img(*env, 0);
}

void	move_up(t_env *env)
{
	int	count;

	count = 0;
	while (count < env->size)
	{
		env->map[count].z += 1;
		count++;
	}
	display_img(*env, 0);
}

void	move_down(t_env *env)
{
	int	count;

	count = 0;
	while (count < env->size)
	{
		env->map[count].z += -1;
		count++;
	}
	display_img(*env, 0);
}

void	move_right(t_env *env)
{
	int	count;

	count = 0;
	while (count < env->size)
	{
		env->map[count].x += 1;
		env->map[count].y += -1;
		count++;
	}
	display_img(*env, 0);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_UP)
		scale_plus(env);
	if (keycode == KEY_DOWN)
		scale_minus(env);
	if (keycode == KEY_I)
		increase(env);
	if (keycode == KEY_O)
		decrease(env);
	if (keycode == KEY_W)
		move_up(env);
	if (keycode == KEY_S)
		move_down(env);
	//if (keycode ==	KEY_A)
	//	move_left(env)
	//if (keycode == KEY_D)
	//	move_right(env);
	return (0);
}
