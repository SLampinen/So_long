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

int	update_goal(t_data *d)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	n = 1;
	d->map[d->coord_goal] = 'G';
	x = ((d->coord_goal % d->line_len));
	while (d->coord_goal > (n * d->line_len))
	{
		y++;
		n++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->goal_o, x * d->wid, y * d->wid);
	d->ext++;
	return (0);
}

int update_zoom(t_data *d)
{
	int	size_win;
	int	pos;
	int win_pos;

	d->w_ind = 0;
	d->h_ind = 0;
	win_pos = 0;
	pos = win_pos + d->coord - (d->win_hei / (2 * d->hei)) - d->line_len;
	size_win = d->win_hei * d->win_wid / (64 * 64);
	while (win_pos < size_win)
	{
		if (pos < 0 || pos > ft_strlen(d->map))
		{
			my_img_put(d, d->map[0], d->wid * d->w_ind, d->hei * d->h_ind);
			ft_printf("win_pos is %i, pos is %i, map[0] is %c\n",win_pos, pos,d->map[0]);
		}
		else
		{
			my_img_put(d, d->map[pos], d->wid * d->w_ind, d->hei * d->h_ind);
			ft_printf("win_pos is %i, pos is %i, map[pos] is %c\n",win_pos, pos,d->map[pos]);
		}
		pos++;
		if (win_pos % (d->win_hei / d->hei) == 4)
		{
			pos = pos - (d->win_hei / d->hei) + d->line_len;
		}
		d->w_ind++;
		if (d->w_ind > (d->line_len - 1))
		{
			d->w_ind = 0;
			d->h_ind++;
		}
		win_pos++;
	}
	ft_printf("coord %i, win_hei %i, hei %i, line_len %i\n",d->coord,d->win_hei, d->hei, d->line_len);
	d->large = 1;
	return (0);
}

int	update_map(t_data *d, char *map, int next)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	n = 1;
	x = (d->coord % d->line_len);
	while (d->coord > ((n++) * d->line_len))
		y++;
	if (next == 0)
	{
		map[d->coord] = '0';
		mlx_put_image_to_window(d->mlx, d->win, d->empty, \
		x * d->wid, y * d->hei);
		if (d->large)
			update_zoom(d);
		return (0);
	}
	if (next == 1)
	{
		map[d->coord] = 'P';
		mlx_put_image_to_window(d->mlx, d->win, d->player, \
		x * d->wid, y * d->hei);
		ft_printf("%i\n", d->steps);
		if (d->large)
			update_zoom(d);
		return (0);
	}
	return (0);
}
