/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:56:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/12 14:09:45 by vafanass         ###   ########.fr       */
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

t_env	split_to_table(t_env env, int i, int count)
{
	char	**split;
	int		j;
	int		x_tmp;

	while (i < env.width)
	{
		split = ft_strsplit(env.array[i], ' ');
		x_tmp = count_tab(split);
		if (x_tmp < env.length)
			error(ERRLINE);
		j = 0;
		while (j < env.length)
		{
			env.map[count].x = j;
			env.map[count].y = i;
			env.map[count].z = ft_atoi(split[j]);
			env.map[count].color = 0x00FFFFFF;
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
	if (!(env.map = malloc(sizeof(t_point) * env.size)))
		error(ERRALLOC);
	env = split_to_table(env, 0, 0);
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
	env.name = file;
	return (env);
}
