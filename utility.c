/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:06:53 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/12 12:39:08 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

void	aff_tabint(int **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	aff_tabchar(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}

int		count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		++i;
	return (i);
}

void	print_coord(t_env env)
{
	int	i;

	i = 0;
	ft_putendl("x y z   color");
	while (i < env.size)
	{
		ft_putnbr(env.map[i].x);
		ft_putchar(' ');
		ft_putnbr(env.map[i].y);
		ft_putchar(' ');
		ft_putnbr(env.map[i].z);
		ft_putchar(' ');
		ft_putnbr(env.map[i].color);
		ft_putchar('\n');
		i++;
	}
}
