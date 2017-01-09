#include "fdf.h"



int main(int argc, char **argv)
{
	t_data        data;
	
	if (argc != 2)
	{
		ft_putstr_fd(ERRARG, 2);
		exit(1);
	}
	ft_putstr(argv[1]);
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, argv[1])) == NULL)
	return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
