/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:05:57 by vafanass          #+#    #+#             */
/*   Updated: 2017/01/17 14:00:29 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SCREEN_X 1920
# define SCREEN_Y 1080
# define SPACE 2

/*
 ** Typedef Here
 */

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
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

typedef	struct s_line
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
	void		*img_ptr;
	char		*img;
	int			img_bpp;
	int			img_endian;
	int			img_size;
	int			space;
	t_point		*map;
	t_point		*coord;
	t_color		color;
	int			length;
	int			width;
	int			size;
	char		**array;
	char		*name;
	double		alpha;
	double		beta;
}				t_env;

/*
 ** Error Message
 */
# define ERRARG "Error: wrong number of arguments.\nUsage : ./fdf [map]\n"
# define ERRALLOC "Error : malloc failed. Exiting.\n"
# define ERRLINE "Wrong line length in the file passed in parameter. Exiting\n"
# define ERRFD "Error with the file descriptor. Exiting.\n"
# define ERRMLX "Error with mlx\n"

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

void	print_coord(t_env env);

t_env	parse_file(char *file);
void	error(char *error);
int		count_tab(char **tab);
void	aff_tabchar(char **tab);
void	aff_tabint(int **tab, int x, int y);
void    free_array(char **array);
void    free_map(t_env env);
void    display_window(t_env env);
void	display_img(t_env env);
int		key_hook(int keycode, t_env *env);
t_color hex_to_rgb(int color);
void    put_pixel(int xtest, t_env env);
t_coord space_to_iso(t_point here, t_env env);

#endif
