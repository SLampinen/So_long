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

int	check_rectangle(char **array, t_data *d)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(array[0]);
	while (i < d->line_amount)
	{
		if (!array[i] || len != ft_strlen(array[i]))
		{
			free(array);
			ft_printf("Error\nMap is not rectangle\n");
			return (0);
		}
		i++;
	}
	if (!check_borders(d, array))
	{
		free(array);
		ft_printf("Error\nMap is not bordered by walls\n");
		return (0);
	}
	free(array);
	return (1);
}

int	validate_map(char *map, t_data *d)
{
	char	**array;
	int		res;

	array = ft_split(map, '\n');
	if (!check_rectangle(array, d))
	{
		free(map);
		return (0);
	}
	res = count(d);
	if (res == 0)
	{
		free(map);
		ft_printf("Error\nMap contains illegal character\n");
		return (0);
	}
	if (res == 1)
	{
		free(map);
		ft_printf("Error\nShould have 1 exit, 1 player & 1+ collectibles\n");
		return (0);
	}
	if (!(has_path(d, map, d->line_amount, d->line_len)))
		return (0);
	return (1);
}
