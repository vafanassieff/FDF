/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:52:50 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/11 16:38:38 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		error(ERRARG);
	env = parse_file(argv[1]);
	
	display_window(env);

	free_map(env);
	free_array(env.array);
	exit(0);
}
