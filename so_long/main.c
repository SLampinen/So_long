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

void	win_game(t_data *d)
{
	ft_printf("You completed game with %i moves\n", d->steps);
	cleanup(d);
	exit (0);
}

int	my_close(t_data *d)
{
	ft_printf("Game ended uncompleted\n");
	cleanup(d);
	exit (0);
}

int	key_hook(int keycode, t_data *d)
{
	if (keycode == 53)
		my_close(d);
	if (keycode == 13 || keycode == 126 || keycode == 91)
		move_up(d->map, d);
	if (keycode == 0 || keycode == 123 || keycode == 86)
		move_left(d->map, d);
	if (keycode == 1 || keycode == 125 || keycode == 84)
		move_down(d->map, d);
	if (keycode == 2 || keycode == 124 || keycode == 88)
		move_right(d->map, d);
	return (0);
}

void	create_mlx(t_data *d)
{
	d->mlx = mlx_init();
}

int	main(int argc, char **argv)
{
	t_data	d;
	char	*map_dup;
	int		fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	d.xcoord = 0;
	d.ycoord = 0;
	d.large = 0;
	d.ext = 0;
	d.line_len = 0;
	d.map = "";
	read_map(fd, &d);
	map_dup = ft_strjoin(d.map, "");
	if (!(validate_map(map_dup, &d)))
		return (0);
	create_map(&d);
	d.steps = 1;
	mlx_key_hook(d.win, key_hook, &d);
	mlx_hook(d.win, 17, 0, my_close, &d);
	mlx_loop(d.mlx);
}
