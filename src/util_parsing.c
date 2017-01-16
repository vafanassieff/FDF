/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:40:00 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/16 14:32:55 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(char **array)
{
	int i;
	int j;

	j = 0;
	i = count_tab(array);
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

//void	free_map(t_env env)
//{
//	int	j;
//
//	j = 0;
//	while (j < env.y)
//	{
//		free(env.map[j]);
//		j++;
//	}
//	free(env.map);
//}
