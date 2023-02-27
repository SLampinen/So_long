/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:20:30 by slampine          #+#    #+#             */
/*   Updated: 2023/02/27 10:48:04 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(void *mlx)
{
	ft_printf("You completed game with %i moves\n", steps);
	mlx_destroy_window(mlx, win);
	free(map);
	exit (0);
}

int	my_close(void *mlx)
{
	mlx_destroy_window(mlx, win);
	free(map);
	exit (0);
}

int	keyhook(int keycode, void *mlx)
{
	if (keycode == 53)
		my_close(mlx);
	if (keycode == 13 || keycode == 126 || keycode == 91)
		(do_move("up"));
	if (keycode == 0 || keycode == 123 || keycode == 86)
		(do_move("left"));
	if (keycode == 1 || keycode == 125 || keycode == 84)
		(do_move("down"));
	if (keycode == 2 || keycode == 124 || keycode == 88)
		(do_move("right"));
	return (0);
}

int	main(int argc, char **argv)
{
	char	*map_dup;
	int		fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	ext = 0;
	line_len = 0;
	map = "";
	read_map(fd);
	map_dup = ft_strjoin(map, "");
	line_amount = steps;
	if (!(validate_map(map_dup, line_len, line_amount)))
	{
		ft_printf("Error with map\n");
		return (0);
	}
	free(map_dup);
	mlx = mlx_init();
	create_map(mlx);
	steps = 1;
	mlx_key_hook(win, keyhook, mlx);
	mlx_hook(win, 17, 0, my_close, mlx);
	mlx_loop(mlx);
}
