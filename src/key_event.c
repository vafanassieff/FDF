/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:36:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/14 19:22:21 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_plus(t_env *env)
{
	env->space = env->space + SPACE;
	display_img(*env);
}

void	scale_minus(t_env *env)
{
	if (env->space > SPACE)
		env->space = env->space - SPACE;
	display_img(*env);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_UP)
		scale_plus(env);
	if (keycode == KEY_DOWN)
		scale_minus(env);
	return (0);
}
