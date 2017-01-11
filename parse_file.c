/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:56:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/11 14:56:24 by vafanass         ###   ########.fr       */
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

int		*split_to_tmp(char **split)
{
	int	*tmp;
	int i;
	int j;

	j = 0;
	i = count_tab(split);
	if(!(tmp = malloc(sizeof(int) * count_tab(split))))
		error(ERRALLOC);
	while (i--)
	{
		tmp[j] = ft_atoi(split[j]);
		j++;
	}
	free_array(split);
	return (tmp);
}

t_env	array_to_int(t_env env)
{	
	int	*tmp;
	char	**split;
	int		i;

	i = 0;
	if(!(env.map = malloc(sizeof(int**) * env.y)))
		error(ERRALLOC);	
	while (i < env.y)
	{
		split = ft_strsplit(env.array[i], ' ');
		env.x = count_tab(split);
		tmp = split_to_tmp(split);
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
	if(!(env.array = malloc(sizeof(int**) * env.y + 1)))
		error(ERRALLOC);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(ERRFD);
	while (get_next_line(fd, &line) == 1)
	{
		if(!(env.array[count] = malloc(sizeof(char*) * ft_strlen(line) + 1)))
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
