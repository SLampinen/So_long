/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:13:43 by slampine          #+#    #+#             */
/*   Updated: 2023/02/20 13:13:44 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
void	*mlx;
void	*win;
void	*wall;
void 	*goal;
void	*goal_open;
void	*empty;
void	*collectible;
void	*player;
char	*map;
int		steps; 
int		width;
int 	height;
int		w_ind;
int		h_ind;
int		coord;
int		coord_goal;
int		line_len;
int		line_amount;
int		col;
int		ext;

int 	my_close(void *mlx);
int 	keyhook(int keycode, void *mlx);
int 	main(int argc, char **argv);
int 	validate_map(char *map, int line_len, int line_amount);
int 	do_move(char *dir);
void	win_game(void *mlx);
int		update_map(char *map, int next);
int 	create_map(void *mlx_get_color_value);
void 	my_img_put(char specifier, int x, int y);
int 	update_goal();
#endif