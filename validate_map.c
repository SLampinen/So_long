/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:18 by slampine          #+#    #+#             */
/*   Updated: 2023/02/27 10:48:13 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_path(char *map, int pos, int sum)
{
	if (map[pos] == 'E')
	{
		map[pos] = '1';
		coord_goal = pos;
		return (sum + 1);
	}
	if (map[pos] == '0' || map[pos] == 'P' || map[pos] == 'C')
	{
		if (map[pos] == 'C')
			sum++;
		map[pos] = '1';
		if (map[pos - 1] == 'E' || map[pos - 1] == 'C' || map[pos - 1] == '0')
			sum = find_path(map, pos - 1, sum);
		if (map[pos + 1] == 'E' || map[pos + 1] == 'C' || map[pos + 1] == '0')
			sum = find_path(map, pos + 1, sum);
		if (map[pos - line_len] == 'E' || map[pos - line_len] == 'C' \
		|| map[pos - line_len] == '0')
			sum = find_path(map, pos - line_len, sum);
		if (map[pos + line_len] == 'E' || map[pos + line_len] == 'C' \
		|| map[pos + line_len] == '0')
			sum = find_path(map, pos + line_len, sum);
	}
	return (sum);
}

int	has_path(char *map, int line_amount, int line_len)
{
	coord = 0;
	while (map[coord] != 'P')
		coord++;
	return (find_path(map, coord, 0));
}

int	check_borders(char **array)
{
	int	index;

	index = 0;
	while (index < line_len - 1)
	{
		if (array[0][index] != '1')
			return (0);
		index++;
	}
	while (index > 0)
	{
		index--;
		if (array[line_amount - 1][index] != '1')
			return (0);
	}
	index = 0;
	while (index < line_amount - 1)
	{
		if (array[index][0] != '1')
			return (0);
		if (array[index][line_len - 2] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	count(void)
{
	int	index;
	int	exits;
	int	player;

	index = 0;
	col = 0;
	player = 0;
	exits = 0;
	while (index < line_amount * line_len)
	{
		if (map[index] != '1' && map[index] != '0' && map[index] != 'C' \
		&& map[index] != 'E' && map[index] != 'P' && map[index] != '\n')
			return (0);
		if (map[index] == 'C')
			col++;
		if (map[index] == 'P')
			player++;
		if (map[index] == 'E')
			exits++;
		index++;
	}
	if (col == 0 || exits != 1 || player != 1)
		return (0);
	return (1);
}

int	validate_map(char *map, int line_len, int line_amount)
{
	char	**array;

	array = ft_split(map, '\n');
	if (!check_borders(array))
	{
		free(array);
		return (0);
	}
	free(array);
	if (!count())
		return (0);
	if ((has_path(map, line_amount, line_len)) != (col + 1))
		ft_printf("No valid path\n");
	else
	{
		ft_printf("map is valid\n");
		return (1);
	}
	return (0);
}
