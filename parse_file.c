/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:56:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/09 19:39:24 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line_file(char *file)
{
	int fd;
	char *line;
	int	result;


	result = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(ERRARG);
	while(get_next_line(fd, &line) == 1)
	{
		result++;
		free(line);
	}
	close(fd);
	return (result);
}
int		count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		++i;
	return (i);
}

void	aff_tabchar(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}

void	aff_tabint(int *tab, int len)
{
	int	i;

	i = 0;
	while (len--)
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
}

int	*split_to_tmp(char **split)
{
	int	*tmp;
	int i;
	int j;

	j = 0;
	i = count_tab(split);
	tmp = malloc(sizeof(int) * count_tab(split));
	while(i--)
	{
		tmp[j] = ft_atoi(split[j]);
		j++;
	}
	return (tmp);
}

int		**array_to_int(char **array)
{
	int	**ret;
	int	lenx;
	int	leny;
	int	*tmp;
	int	i;

	i = 0;
	leny = count_tab(array);
	while (i < leny)
	{
		lenx = count_tab(ft_strsplit(array[i], ' '));
		ret = malloc(sizeof(int**) * count_tab(array));
		tmp = split_to_tmp(ft_strsplit(array[i], ' '));
		aff_tabint(tmp, lenx);
		ft_putchar('\n');
		ret[i] = tmp;
		i++;
	}
	ret = 0;
	return (ret);	
}

int		**parse_file(char *file)
{
	int		fd;
	char	**array;
	char	*line;
	int		count;
	int		**map;

	count = 0;
	array = malloc(sizeof(int**) * count_line_file(file) + 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(ERRARG);
	while (get_next_line(fd, &line) == 1)
	{
		array[count] = malloc(sizeof(char*) * ft_strlen(line) + 1);
		strcpy(array[count], line);
		count++;
		free(line);
	}
	close(fd);
	array[count] = NULL;
	//	aff_tabchar(array);
	map = array_to_int(array);
	exit(1);
	map = 0;
	return (map);
}
