/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:09:20 by slampine          #+#    #+#             */
/*   Updated: 2023/02/27 10:48:08 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_goal(void)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	n = 1;
	x = ((coord_goal % line_len));
	while (coord_goal > (n * line_len))
	{
		y++;
		n++;
	}
	mlx_put_image_to_window(mlx, win, goal_open, x * width, y * width);
	ext++;
	return (0);
}

int	update_map(char *map, int next)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	n = 1;
	x = (coord % line_len);
	while (coord > ((n++) * line_len))
		y++;
	if (next == 0)
	{
		map[coord] = '0';
		mlx_put_image_to_window(mlx, win, empty, x * width, y * height);
		return (0);
	}
	if (next == 1)
	{
		map[coord] = 'P';
		mlx_put_image_to_window(mlx, win, player, x * width, y * height);
		ft_printf("%i\n", steps);
		return (0);
	}
	return (0);
}
