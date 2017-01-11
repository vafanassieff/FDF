/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:56:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/11 21:05:57 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line_file(char *file)
{
	int		fd;
	char	*line;
	int		result;

	result = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(ERRFD);
	while (get_next_line(fd, &line) == 1)
	{
		result++;
		free(line);
	}
	close(fd);
	return (result);
}

void	print_coord(t_env env)
{
	int all;
	int	i;

	all = env.width * env.length;
	i = 0;
	ft_putendl("x y z   color");
	while (i < all)
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

t_env	split_to_table(t_env env)
{
	t_point	tmp;
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	if (!(env.map = malloc(sizeof(t_point) * env.size)))
		error(ERRALLOC);
	while (i < env.width)
	{
		split = ft_strsplit(env.array[i], ' ');
		j = 0;
		while (j < env.length)
		{
			tmp.x = j;
			tmp.y = i;
			tmp.z = ft_atoi(split[j]);
			tmp.color = 0x00FFFFFF; //Bosse sur un moyen de recup la couleur (z,couleur)
			env.map[count] = tmp;
			j++;
			count++;
		}
		free_array(split);
		i++;
	}
	return (env);
}

t_env	array_to_int(t_env env)
{
	char **split;

	split = ft_strsplit(env.array[0], ' ');
	env.length = count_tab(split);
	free_array(split);
	env.size = env.length * env.width;
	env = split_to_table(env);
	print_coord(env);
	sleep(40);
	return (env);
}

t_env	parse_file(char *file)
{
	int		fd;
	char	*line;
	int		count;
	t_env	env;

	count = 0;
	env.width = count_line_file(file);
	if (!(env.array = malloc(sizeof(int**) * env.width)))
		error(ERRALLOC);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(ERRFD);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(env.array[count] = malloc(sizeof(char*) * ft_strlen(line) + 1)))
			error(ERRALLOC);
		strcpy(env.array[count], line);
		count++;
		free(line);
	}
	close(fd);
	env.array[count] = NULL;
	env = array_to_int(env);
	return (env);
}
