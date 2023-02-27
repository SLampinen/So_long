/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:22:54 by slampine          #+#    #+#             */
/*   Updated: 2023/02/27 10:05:00 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(int fd)
{
	char	*line;

	steps = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line_len == 0)
			line_len = ft_strlen(line);
		map = ft_strjoin(map, line);
		free(line);
		steps++;
	}
	return (steps);
}

void	my_img_put(char specifier, int x, int y)
{
	if (specifier == '1')
		mlx_put_image_to_window(mlx, win, wall, x, y);
	if (specifier == 'E')
		mlx_put_image_to_window(mlx, win, goal, x, y);
	if (specifier == '0')
		mlx_put_image_to_window(mlx, win, empty, x, y);
	if (specifier == 'P')
		mlx_put_image_to_window(mlx, win, player, x, y);
	if (specifier == 'C')
		mlx_put_image_to_window(mlx, win, collectible, x, y);
}

int	create_images(void)
{
	wall = mlx_xpm_file_to_image(mlx, "open.xpm", &width, &height);
	goal = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height);
	goal_open = mlx_xpm_file_to_image(mlx, "exit_open.xpm", &width, &height);
	empty = mlx_xpm_file_to_image(mlx, "empty.xpm", &width, &height);
	collectible = mlx_xpm_file_to_image(mlx, "col.xpm", &width, &height);
	player = mlx_new_image(mlx, width, height);
	return (0);
}

int	create_map(void *mlx)
{
	int	win_width;
	int	size_map;
	int	pos;

	w_ind = 0;
	h_ind = 0;
	pos = 0;
	create_images();
	win_width = width * (line_len - 1);
	win = mlx_new_window(mlx, win_width, line_amount * height, "The game");
	size_map = line_len * line_amount;
	while (pos < size_map)
	{
		my_img_put(map[pos], width * w_ind, height * h_ind);
		w_ind++;
		if (w_ind * width > win_width)
		{
			w_ind = 0;
			h_ind++;
		}
		pos++;
	}
	return (1);
}
