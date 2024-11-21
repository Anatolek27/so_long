/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:30:44 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:42:04 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pressed_key(int key, t_data *data)
{
	if (key == 53)
	{
		write(1, "Game closed !", 13);
		close_game(data);
	}
	if (key == 124 || key == 2)
		move_right(data);
	if (key == 123 || key == 0)
		move_left(data);
	if (key == 126 || key == 13)
		move_up(data);
	if (key == 125 || key == 1)
		move_down(data);
	return (0);
}

int	ft_exit(void)
{
	write(1, "Game closed !", ft_strlen("Game closed !"));
	exit(0);
}

void	render_movements(t_data *data)
{
	if (data->map != NULL && data->mlx_ptr != NULL)
	{
		create_images(data);
		data->mlx_win = mlx_new_window(data->mlx_ptr, 
				data->width * 60, data->height * 60, "so_long");
		if (data->mlx_win == NULL)
			close_game(data);
		map_render(data);
		mlx_loop_hook(data->mlx_ptr, &map_render, data);
		mlx_hook(data->mlx_win, 2, 0, &pressed_key, data);
		mlx_hook(data->mlx_win, 17, 0, ft_exit, &data);
		mlx_loop(data->mlx_ptr);
	}
	close_game(data);
}
