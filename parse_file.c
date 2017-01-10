/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:56:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/10 17:47:36 by vafanass         ###   ########.fr       */
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
		print_error(ERRARG);
	while (get_next_line(fd, &line) == 1)
	{
		result++;
		free(line);
	}
	close(fd);
	return (result);
}

int		*split_to_tmp(char **split)
{
	int	*tmp;
	int i;
	int j;

	j = 0;
	i = count_tab(split);
	tmp = malloc(sizeof(int) * count_tab(split));
	while (i--)
	{
		tmp[j] = ft_atoi(split[j]);
		j++;
	}
	return (tmp);
}


// voir les leaks ici
t_env	array_to_int(t_env env)
{
	int	*tmp;
	int	i;

	i = 0;
	env.map = malloc(sizeof(int**) * env.y);
	while (i < env.y)
	{
		env.x = count_tab(ft_strsplit(env.array[i], ' '));
		tmp = split_to_tmp(ft_strsplit(env.array[i], ' '));
		env.map[i] = malloc(sizeof(int*) * env.x);
		env.map[i] = tmp;
		i++;
	}
	return (env);
}

t_env	parse_file(char *file)
{
	int		fd;
	char	*line;
	int		count;
	t_env	env;

	count = 0;
	env.y = count_line_file(file);
	env.array = malloc(sizeof(int**) * env.y + 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(ERRARG);
	while (get_next_line(fd, &line) == 1)
	{
		env.array[count] = malloc(sizeof(char*) * ft_strlen(line) + 1);
		strcpy(env.array[count], line);
		count++;
		free(line);
	}
	close(fd);
	env.array[count] = NULL;
	env = array_to_int(env);
	free(env.array);
	return (env);
}
