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

int	move_down(char *map, t_data *d)
{
	if (map[d->coord + d->line_len] == '0' \
	|| map[d->coord + d->line_len] == 'C')
	{
		d->ycoord++;
		update_map(d, map, 0);
		d->coord = d->coord + d->line_len;
		if (map[d->coord] == 'C')
			d->col--;
		if (d->ext == 0 && d->col == 0)
			update_goal(d);
		update_map(d, map, 1);
		d->steps++;
		return (1);
	}
	if (map[d->coord + d->line_len] == 'G')
	{
		win_game(d);
		return (1);
	}
	return (0);
}

int	move_up(char *map, t_data *d)
{
	if (map[d->coord - d->line_len] == '0' \
	|| map[d->coord - d->line_len] == 'C')
	{
		d->ycoord--;
		update_map(d, map, 0);
		d->coord = d->coord - d->line_len;
		if (map[d->coord] == 'C')
			d->col--;
		if (d->ext == 0 && d->col == 0)
			update_goal(d);
		update_map(d, map, 1);
		d->steps++;
		return (1);
	}
	if (map[d->coord - d->line_len] == 'G')
	{
		win_game(d);
		return (1);
	}
	return (0);
}

int	move_left(char *map, t_data *d)
{
	if (map[d->coord - 1] == '0' || map[d->coord - 1] == 'C')
	{
		d->xcoord++;
		update_map(d, map, 0);
		d->coord = d->coord - 1;
		if (map[d->coord] == 'C')
			d->col--;
		if (d->ext == 0 && d->col == 0)
			update_goal(d);
		update_map(d, map, 1);
		d->steps++;
		return (1);
	}
	if (map[d->coord - 1] == 'G')
	{
		win_game(d);
		return (1);
	}
	return (0);
}

int	move_right(char *map, t_data *d)
{
	if (map[d->coord + 1] == '0' || map[d->coord + 1] == 'C')
	{
		d->xcoord--;
		update_map(d, map, 0);
		d->coord = d->coord + 1;
		if (map[d->coord] == 'C')
			d->col--;
		if (d->ext == 0 && d->col == 0)
			update_goal(d);
		update_map(d, map, 1);
		d->steps++;
		return (1);
	}
	if (map[d->coord + 1] == 'G')
	{
		win_game(d);
		return (1);
	}
	return (0);
}
