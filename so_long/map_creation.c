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

void	my_img_put(t_data *d, char specifier, int x, int y)
{
	if (specifier == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->wall, x, y);
	if (specifier == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->goal, x, y);
	if (specifier == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->empty, x, y);
	if (specifier == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->player, x, y);
	if (specifier == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->collectible, x, y);
	if (specifier == 'G')
		mlx_put_image_to_window(d->mlx, d->win, d->goal_o, x, y);
}

void	create_images(t_data *d)
{
	d->wall = mlx_xpm_file_to_image(d->mlx, \
	"textures/wall.xpm", &d->wid, &d->hei);
	d->goal = mlx_xpm_file_to_image(d->mlx, \
	"textures/door.xpm", &d->wid, &d->hei);
	d->goal_o = mlx_xpm_file_to_image(d->mlx, \
	"textures/exit_o.xpm", &d->wid, &d->hei);
	d->empty = mlx_xpm_file_to_image(d->mlx, \
	"textures/empty.xpm", &d->wid, &d->hei);
	d->collectible = mlx_xpm_file_to_image(d->mlx, \
	"textures/col.xpm", &d->wid, &d->hei);
	d->player = mlx_new_image(d->mlx, d->wid, d->hei);
}

void	create_win(t_data *d, int win_wid)
{
	int	win_max;

	win_max = 5;
	d->win_hei = d->line_amount * d->hei;
	if (win_wid > d->wid * win_max)
	{
		d->large = 1;
		d->win_wid = d->wid * win_max;
	}
	if (d->win_hei > d->hei * win_max)
	{
		d->large = 1;
		d->win_hei = d->hei * win_max;
	}
	d->win = mlx_new_window(d->mlx, d->win_wid, d->win_hei, "Game");
}

void	create_map(t_data *d)
{
	int	size_map;
	int	pos;

	d->w_ind = 0;
	d->h_ind = 0;
	pos = 0;
	create_mlx(d);
	create_images(d);
	d->win_wid = d->wid * (d->line_len - 1);
	create_win(d, d->win_wid);
	size_map = d->line_len * d->line_amount;
	while (pos < size_map)
	{
		my_img_put(d, d->map[pos], d->wid * d->w_ind, d->hei * d->h_ind);
		d->w_ind++;
		if (d->w_ind * d->wid > d->wid * (d->line_len - 1))
		{
			d->w_ind = 0;
			d->h_ind++;
		}
		pos++;
	}
	if (d->large)
		update_zoom(d);
}
