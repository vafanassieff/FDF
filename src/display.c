/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:25 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/19 16:42:09 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_bis(t_line l, t_env env)
{
	while (l.x <= l.vx)
	{
		if (l.steep)
		{
			l.xfinal = (l.x + env.orx) * 4 + (l.y + env.ory) * env.isize;
			if (l.xfinal < env.isize * SCREEN_Y)
				put_pixel(l.xfinal, env);
		}
		else
		{
			l.xfinal = (l.y + env.orx) * 4 + (l.x + env.ory) * env.isize;
			if (l.xfinal < env.isize * SCREEN_Y)
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

void	line(t_coord u, t_coord v, t_env env)
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
	l.uy = u.y;
	line_bis(l, env);
}

void	display_img(t_env env, int i)
{
	t_coord *c;

	if (!(c = malloc(sizeof(t_coord) * 3)))
		error(ERRALLOC);
	if (!(env.iptr = mlx_new_image(env.mlx, SCREEN_X, SCREEN_Y)))
		error(ERRMLX);
	env.img = mlx_get_data_addr(env.iptr, &env.bpp, &env.isize, &env.endian);
	while (i < env.size)
	{
		env.color = hex_to_rgb(env.map[i].color);
		c[0] = space_to_iso(env.map[i], env);
		if (test_coord(c[0], env) == 0)
		{
			if (i + 1 < env.size)
				c[1] = space_to_iso(env.map[i + 1], env);
			if (i + env.length < env.size)
				c[2] = space_to_iso(env.map[i + env.length], env);
			if (env.map[i].x < env.length - 1 && (test_coord(c[1], env) == 0))
				line(c[0], c[1], env);
			if (env.map[i].y < env.width - 1 && (test_coord(c[2], env) == 0))
				line(c[0], c[2], env);
		}
		i++;
	}
	env.put = mlx_put_image_to_window(env.mlx, env.win, env.iptr, 0, 0);
}

void	display_window(t_env env)
{
	if (!(env.mlx = mlx_init()))
		error(ERRMLX);
	if (!(env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, env.name)))
		error(ERRMLX);
	env.orx = TEST_X;
	env.ory = TEST_Y;
	env.space = SPACE;
	env.map = malloc(sizeof(t_point) * env.size);
	env.map = env.original;
	display_img(env, 0);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
}
