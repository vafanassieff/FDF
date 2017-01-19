/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:57:41 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/19 18:15:18 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		hex_to_rgb(int color)
{
	t_color	ret;

	ret.r = color & 0xff;
	ret.g = (color >> 8) & 0xff;
	ret.b = (color >> 16) & 0xff;
	return (ret);
}

void		put_pixel(int xtest, t_env env)
{
	ft_memset(&env.img[0 + xtest], env.color.b, 1);
	ft_memset(&env.img[1 + xtest], env.color.g, 1);
	ft_memset(&env.img[2 + xtest], env.color.r, 1);
}

t_coord		space_to_iso(t_point here, t_env env)
{
	t_coord	coord;
	double	alpha;
	double	beta;

	alpha = M_PI / 180 * 0;
	beta = M_PI / 180 * 0;
	coord.x = (here.x * cos(alpha)) - (here.y * cos(beta));
	coord.y = (-here.z) + (here.x * sin(alpha)) + (here.y * cos(beta));
	coord.x = coord.x * env.space + 910 - env.length/2 * env.space;
	coord.y = coord.y * env.space + 540 - env.width/2 * env.space;
	return (coord);
}

int			test_coord(t_coord c, t_env env)
{
	if (c.x <= SCREEN_X - env.orx && c.x >= -env.orx && c.y
			<= SCREEN_Y - env.ory && c.y >= -env.ory)
		return (0);
	return (1);
}
