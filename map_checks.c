/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:28 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:39:05 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangular_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != j)
		{
			ft_error("Map not rectangular", data);
			close_game(data);
		}
		i++;
	}
	if (data->content.count_e != 1 || data->content.count_p != 1)
	{
		ft_error("Only one player and one exit expected", data);
		close_game(data);
	}
	if (data->content.count_c < 1)
	{
		ft_error("no collectibles on map", data);
		close_game(data);
	}
}

void	scan_errors2(t_data *data)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c != '1' && c != '0' && c != 'E'
				&& c != 'C' && c != 'P' && c != '\n')
			{
				ft_error("not recognized charcaters in map", data);
				close_game(data);
			}
			j++;
		}
		i++;
	}
	rectangular_check(data);
	map_test(data, data->pos.x, data->pos.y);
}

void	scan_errors(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
		{
			ft_error("map not surrounded by walls", data);
		}
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
		{
			ft_error("map not surrounded by walls", data);
		}
		i++;
	}
	scan_errors2(data);
}

void	first_scan(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->content.count_c++;
			if (data->map[i][j] == 'P')
			{
				data->pos.x = i;
				data->pos.y = j;
				data->content.count_p++;
			}
			if (data->map[i][j] == 'E')
				data->content.count_e++;
			j++;
		}
		i++;
	}
}
