/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:30:57 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:30:57 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_data *data)
{
	write(1, ft_itoa(data->count), ft_strlen(ft_itoa(data->count++)));
	write(1, "\n", 1);
	write(1, "You won !", 9);
	close_game(data);
}

void	move_up(t_data *data)
{
	if (data->map[data->pos.x - 1][data->pos.y] == '1' || data->pos.x <= 0)
		return ;
	if (data->map[data->pos.x - 1][data->pos.y] == 'E')
	{
		if (data->content.collected != data->content.count_c)
			return ;
		else
		{
			win_game(data);
			return ;
		}
	}
	if (data->map[data->pos.x - 1][data->pos.y] == 'C')
		data->content.collected++;
	data->map[data->pos.x][data->pos.y] = '0';
	data->map[data->pos.x - 1][data->pos.y] = 'P';
	map_render(data);
	data->count++;
	write(1, ft_itoa(data->count), ft_strlen(ft_itoa(data->count)));
	write(1, "\n", 1);
	data->pos.x = data->pos.x - 1;
}

void	move_down(t_data *data)
{
	if (data->map[data->pos.x + 1][data->pos.y] == '1' || data->pos.x <= 0)
		return ;
	if (data->map[data->pos.x + 1][data->pos.y] == 'E')
	{
		if (data->content.collected != data->content.count_c)
			return ;
		else
		{
			win_game(data);
			return ;
		}
	}
	if (data->map[data->pos.x + 1][data->pos.y] == 'C')
		data->content.collected++;
	data->map[data->pos.x][data->pos.y] = '0';
	data->map[data->pos.x + 1][data->pos.y] = 'P';
	map_render(data);
	data->count++;
	write(1, ft_itoa(data->count), ft_strlen(ft_itoa(data->count)));
	write(1, "\n", 1);
	data->pos.x = data->pos.x + 1;
}

void	move_right(t_data *data)
{
	if (data->map[data->pos.x][data->pos.y + 1] == '1' || data->pos.x <= 0)
		return ;
	if (data->map[data->pos.x][data->pos.y + 1] == 'E')
	{
		if (data->content.collected != data->content.count_c)
			return ;
		else
		{
			win_game(data);
			return ;
		}
	}
	if (data->map[data->pos.x][data->pos.y + 1] == 'C')
		data->content.collected++;
	data->map[data->pos.x][data->pos.y] = '0';
	data->map[data->pos.x][data->pos.y + 1] = 'P';
	map_render(data);
	data->count++;
	write(1, ft_itoa(data->count), ft_strlen(ft_itoa(data->count)));
	write(1, "\n", 1);
	data->pos.y = data->pos.y + 1;
}

void	move_left(t_data *data)
{
	if (data->map[data->pos.x][data->pos.y - 1] == '1' || data->pos.x <= 0)
		return ;
	if (data->map[data->pos.x][data->pos.y - 1] == 'E')
	{
		if (data->content.collected != data->content.count_c)
			return ;
		else
		{
			win_game(data);
			return ;
		}
	}
	if (data->map[data->pos.x][data->pos.y - 1] == 'C')
		data->content.collected++;
	data->map[data->pos.x][data->pos.y] = '0';
	data->map[data->pos.x][data->pos.y - 1] = 'P';
	map_render(data);
	data->count++;
	write(1, ft_itoa(data->count), ft_strlen(ft_itoa(data->count)));
	write(1, "\n", 1);
	data->pos.y = data->pos.y - 1;
}
