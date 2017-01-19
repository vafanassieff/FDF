/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:40:00 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/19 18:05:55 by vafanass         ###   ########.fr       */
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
