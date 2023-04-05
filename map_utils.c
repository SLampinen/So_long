/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:56:47 by slampine          #+#    #+#             */
/*   Updated: 2023/03/03 08:56:49 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_data *d)
{
	char	*line;

	d->line_amount = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (d->line_len == 0)
			d->line_len = ft_strlen(line);
		d->map = ft_strjoin(d->map, line);
		free(line);
		d->line_amount++;
	}
}

int	find_path(t_data *d, char *map, int pos, int sum)
{
	char	*legal;

	legal = "EC0";
	if (map[pos] == 'E')
	{
		map[pos] = '1';
		d->coord_goal = pos;
		return (sum + 1);
	}
	if (map[pos] == '0' || map[pos] == 'P' || map[pos] == 'C')
	{
		if (map[pos] == 'C')
			sum++;
		map[pos] = '1';
		if (ft_strchr(legal, map[pos - 1]))
			sum = find_path(d, map, pos - 1, sum);
		if (ft_strchr(legal, map[pos + 1]))
			sum = find_path(d, map, pos + 1, sum);
		if (ft_strchr(legal, map[pos - d->line_len]))
			sum = find_path(d, map, pos - d->line_len, sum);
		if (ft_strchr(legal, map[pos + d->line_len]))
			sum = find_path(d, map, pos + d->line_len, sum);
	}
	return (sum);
}

int	has_path(t_data *d, char *map, int line_amount, int line_len)
{
	d->coord = 0;
	while (map[d->coord] != 'P')
		d->coord++;
	if (find_path(d, map, d->coord, 0) != d->col + 1)
	{
		free(map);
		ft_printf("Error\nNo valid path\n");
		return (0);
	}
	free(map);
	return (1);
}

int	check_borders(t_data *d, char **array)
{
	int	index;

	index = 0;
	while (index < d->line_len - 1)
	{
		if (array[0][index] != '1')
			return (0);
		index++;
	}
	while (index > 0)
	{
		index--;
		if (array[d->line_amount - 1][index] != '1')
			return (0);
	}
	while (index < d->line_amount - 1)
	{
		if (array[index][0] != '1')
			return (0);
		if (array[index][d->line_len - 2] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	count(t_data *d)
{
	int		index;
	int		exits;
	int		player;
	char	*legal;

	legal = "01PCE\n";
	index = 0;
	d->col = 0;
	player = 0;
	exits = 0;
	while (index < d->line_amount * d->line_len)
	{
		if (!ft_strchr(legal, d->map[index]))
			return (0);
		if (d->map[index] == 'C')
			d->col++;
		if (d->map[index] == 'P')
			player++;
		if (d->map[index] == 'E')
			exits++;
		index++;
	}
	if (d->col == 0 || exits != 1 || player != 1)
		return (1);
	return (2);
}
