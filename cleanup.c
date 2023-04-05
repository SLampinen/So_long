/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:54:30 by slampine          #+#    #+#             */
/*   Updated: 2023/03/02 13:54:32 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cleanup(t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
	free(d->wall);
	free(d->goal);
	free(d->goal_o);
	free(d->empty);
	free(d->collectible);
	free(d->player);
	free(d->map);
	return (0);
}
