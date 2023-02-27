/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:21:25 by slampine          #+#    #+#             */
/*   Updated: 2023/02/27 10:35:36 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(char *map)
{
	if (map[coord + line_len] == '0' || map[coord + line_len] == 'C')
	{
		update_map(map, 0);
		coord = coord + line_len;
		if (map[coord] == 'C')
			col--;
		if (ext == 0 && col == 0)
			update_goal();
		update_map(map, 1);
		steps++;
		return (1);
	}
	if (map[coord + line_len] == 'E' && col == 0)
	{
		win_game(mlx);
		return (1);
	}
	return (0);
}

int	move_up(char *map)
{
	if (map[coord - line_len] == '0' || map[coord - line_len] == 'C')
	{
		update_map(map, 0);
		coord = coord - line_len;
		if (map[coord] == 'C')
			col--;
		if (ext == 0 && col == 0)
			update_goal();
		update_map(map, 1);
		steps++;
		return (1);
	}
	if (map[coord - line_len] == 'E' && col == 0)
	{
		win_game(mlx);
		return (1);
	}
	return (0);
}

int	move_left(char *map)
{
	if (map[coord - 1] == '0' || map[coord - 1] == 'C')
	{
		update_map(map, 0);
		coord = coord - 1;
		if (map[coord] == 'C')
			col--;
		if (ext == 0 && col == 0)
			update_goal();
		update_map(map, 1);
		steps++;
		return (1);
	}
	if (map[coord - 1] == 'E' && col == 0)
	{
		win_game(mlx);
		return (1);
	}
	return (0);
}

int	move_right(char *map)
{
	if (map[coord + 1] == '0' || map[coord + 1] == 'C')
	{
		update_map(map, 0);
		coord = coord + 1;
		if (map[coord] == 'C')
			col--;
		if (ext == 0 && col == 0)
			update_goal();
		update_map(map, 1);
		steps++;
		return (1);
	}
	if (map[coord + 1] == 'E' && col == 0)
	{
		win_game(mlx);
		return (1);
	}
	return (0);
}

int	do_move(char *dir)
{
	if (!ft_strncmp(dir, "up", ft_strlen(dir)))
		return (move_up(map));
	if (!ft_strncmp(dir, "down", ft_strlen(dir)))
		return (move_down(map));
	if (!ft_strncmp(dir, "left", ft_strlen(dir)))
		return (move_left(map));
	if (!ft_strncmp(dir, "right", ft_strlen(dir)))
		return (move_right(map));
	return (0);
}
