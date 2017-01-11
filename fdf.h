/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:05:57 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/11 14:56:19 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
 ** Typedef Here
 */

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

typedef struct	s_env
{
	int			**map;
	int			x;
	int			y;
	char		**array;

}				t_env;

/*
 ** Error Message
 */

# define ERRARG "Error: wrong number of arguments.\nUsage : ./fdf [map]\n"
# define ERRALLOC "Error : malloc failed\n"
# define ERRLINE "Wrong line length in the file passed in parameter"
# define ERRFD "Error with the file descriptor"

/*
 ** Mandatory Library 
 */

# include "libft.h"
# include "mlx.h"
# include "mlx_key_osx.h"
/*
 ** Usefull Library
 */

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
 ** Oublie pas de les delete les bails en trop
 */

t_env	parse_file(char *file);
void	error(char *error);
int		count_tab(char **tab);
void	aff_tabchar(char **tab);
void	aff_tabint(int **tab, int x, int y);
void    free_array(char **array);
void    free_map(t_env env);
#endif
