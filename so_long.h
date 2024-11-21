/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:33 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:03 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct pos_s
{
	int	x;
	int	y;
}		t_pos;

typedef struct cnt_s
{
	char	exit;
	char	collectible;
	char	player;
	char	wall;
	char	floor;
	int		count_p;
	int		count_e;
	int		count_c;
	int		collected;
}		t_cnt;

typedef struct img_s
{
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collectible;
	char	*exit;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collectible;
}		t_img;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	int		error;
	char	**map;
	char	**cpy;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}		t_data;

int		ft_error(char *error, t_data *data);
int		count_lines(char **map);
char	**get_map(char *file, t_data *data);
void	first_scan(t_data *data);
void	close_game(t_data *data);
void	close_game2(t_data *data);
void	scan_errors(t_data *data);
void	map_test(t_data *data, int i, int j);
void	render_movements(t_data *data);
int		pressed_keys(int key, t_data *data);
int		ft_exit(void);
void	win_game(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	create_images(t_data *data);
void	put_images(t_data *data);
int		map_render(t_data *data);

#endif
