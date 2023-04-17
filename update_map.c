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
	mlx_put_image_to_window(d->mlx, d->win, d->goal_o, x * d->img_wid, y * d->img_wid);
	d->ext++;
	return (0);
}

char	pos_to_map(t_data *d, int win_x, int win_y, int win_size)
{
	char res;
	int pos;
	int	p_x;
	int	p_y;
	int dif_x;
	int dif_y;
	int	coordx;
	int	coordy;

	//ft_printf("win_x %i, win_y %i\n",win_x, win_y);
	p_x = d->coord % d->line_len;
	p_y = d->coord / d->line_len;
	//ft_printf("p_x %i, p_y %i\n", p_x, p_y);
	dif_x = win_x - p_x;
	dif_y = win_y - p_y;
	ft_printf("dif_x %i, dif_y %i\n",dif_x, dif_y);
	coordx = p_x + dif_x;
	coordy = p_y + dif_y;
	pos = coordx + (coordy * d->line_len);
	if (coordx < 0 || coordx >= d->line_len)
	{
		pos = 0;
	}
	if (coordy < 0 || coordy >= d->line_amount)
	{
		pos = 0;
	}
	//ft_printf("coordx %i, coordy %i\n",coordx, coordy);
	//ft_printf("pos %i, map[pos] %c\n\n", pos, d->map[pos]);
	res = d->map[pos];
	return (res);
}
int	update_zoom(t_data *d)
{
	int	win_pos;
	int	win_size;
	int	win_x;
	int	win_y;
	char spec;

	win_pos = 0;
	win_y = 0;
	win_x = 0;
	win_size = d->win_hei * d->win_wid / (d->img_hei * d->img_wid);
	while (win_pos < win_size)
	{
		spec = pos_to_map(d, win_x, win_y, win_size);
		//ft_printf("spec %c, win_x %i, win_y %i\n", spec, win_x, win_y);
		my_img_put(d, spec, win_x * d->img_wid, win_y * d->img_hei);
		win_x++;
		if (win_x >= d->win_wid / d->img_wid)
		{
			win_x = 0;
			win_y++;
		}
		win_pos++;
	}
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
	if (d->large)
	{
		if (next == 0)
			map[d->coord] = '0';
		if (next == 1)
			map[d->coord] = 'P';
		update_zoom(d);
		return (0);
	}
	x = (d->coord % d->line_len);
	while (d->coord > ((n++) * d->line_len))
		y++;
	if (next == 0)
	{
		map[d->coord] = '0';
		mlx_put_image_to_window(d->mlx, d->win, d->empty, \
		x * d->img_wid, y * d->img_hei);
		return (0);
	}
	if (next == 1)
	{
		map[d->coord] = 'P';
		mlx_put_image_to_window(d->mlx, d->win, d->player, \
		x * d->img_wid, y * d->img_hei);
		ft_printf("%i\n", d->steps);
		return (0);
	}
	return (0);
}
