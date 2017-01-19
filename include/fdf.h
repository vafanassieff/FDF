/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:05:57 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/19 18:16:45 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SCREEN_X 1920
# define SCREEN_Y 1080
# define SPACE 4
# define TEST_X 500
# define TEST_Y 100

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
** Typedef Here
*/

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef	struct	s_color
{
	char			r;
	char			g;
	char			b;
}				t_color;

typedef	struct	s_line
{
	int			steep;
	int			xfinal;
	int			dx;
	int			dy;
	int			derror;
	int			error;
	int			x;
	int			y;
	int			vx;
	int			vy;
	int			uy;

}				t_line;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*iptr;
	char		*img;
	int			bpp;
	int			endian;
	int			isize;
	int			put;
	int			space;
	t_point		*original;
	t_point		*map;
	t_color		color;
	int			length;
	int			width;
	int			size;
	char		**array;
	char		*name;
	int			orx;
	int			ory;
}				t_env;

/*
** Error Message
*/

# define ERRARG "Error : wrong number of arguments.\nUsage : ./fdf [map]\n"
# define ERRTYPE "No Data Found"
# define ERRALLOC "Error : malloc failed. Exiting.\n"
# define ERRLINE "Wrong line length in the file passed in parameter. Exiting\n"
# define ERRFD "Error with the file descriptor. Exiting.\n"
# define ERRMLX "Error with mlx\n"

void			print_coord(t_env env);
t_env			parse_file(char *file);
void			error(char *error);
int				count_tab(char **tab);
void			aff_tabchar(char **tab);
void			aff_tabint(int **tab, int x, int y);
void			free_array(char **array);
void			free_map(t_env env);
void			display_window(t_env env);
void			display_img(t_env env, int count);
int				key_hook(int keycode, t_env *env);
t_color			hex_to_rgb(int color);
void			put_pixel(int xtest, t_env env);
t_coord			space_to_iso(t_point here, t_env env);
int				test_coord(t_coord c, t_env env);

#endif
