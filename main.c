/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:52:50 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/10 17:47:38 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_env	env;
	if (argc != 2)
		print_error(ERRARG);
	env.map = 0;
	env = parse_file(argv[1]);
	aff_tabint(env.map, env.x, env.y);
	sleep(15);
	exit(1);

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, argv[1])) == NULL)
	return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
