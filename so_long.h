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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*goal;
	void	*goal_o;
	void	*empty;
	void	*collectible;
	void	*player;
	char	*map;
	int		steps;
	int		wid;
	int		hei;
	int		w_ind;
	int		h_ind;
	int		coord;
	int		coord_goal;
	int		line_len;
	int		line_amount;
	int		col;
	int		ext;
	int		xcoord;
	int		ycoord;
	int		large;
	int		win_wid;
	int		win_hei;
}	t_data;

int		my_close(t_data *data);
int		key_hook(int keycode, t_data *data);
int		main(int argc, char **argv);
void	read_map(int fd, t_data *data);
int		validate_map(char *map, t_data *data);
int		check_rectangle(char **array, t_data *d);
int		check_borders(t_data *d, char **array);
int		find_path(t_data *d, char *map, int pos, int sum);
int		has_path(t_data *d, char *map, int line_amount, int line_len);
int		count(t_data *d);
void	create_map(t_data *data);
void	create_mlx(t_data *data);
int		update_map(t_data *data, char *map, int next);
void	my_img_put(t_data *data, char specifier, int x, int y);
int		update_goal(t_data *data);
int		move_right(char *map, t_data *d);
int		move_down(char *map, t_data *d);
int		move_left(char *map, t_data *d);
int		move_up(char *map, t_data *d);
void	win_game(t_data *data);
int		cleanup(t_data *d);
int update_zoom(t_data *d);
#endif
