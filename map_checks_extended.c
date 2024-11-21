/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_extended.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:21 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:33 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_final_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->cpy[i])
	{
		j = 0;
		while (data->cpy[i][j])
		{
			if (data->cpy[i][j] == 'E' || data->cpy[i][j] == 'C')
			{
				ft_error("map not playable", data);
				close_game(data);
			}
			j++;
		}
		i++;
	}
}

void	map_test(t_data *data, int i, int j)
{
	while (i > 0 && i < data->width && j > 0 && j < data->height)
	{
		if (data->cpy[i + 1][j] != '1' && data->cpy[i + 1][j] != '2')
		{
			data->cpy[i + 1][j] = '2';
			map_test(data, i + 1, j);
		}
		else if (data->cpy[i - 1][j] != '1' && data->cpy[i - 1][j] != '2')
		{
			data->cpy[i - 1][j] = '2';
			map_test(data, i - 1, j);
		}
		else if (data->cpy[i][j + 1] != '1' && data->cpy[i][j + 1] != '2')
		{
			data->cpy[i][j + 1] = '2';
			map_test(data, i, j + 1);
		}
		else if (data->cpy[i][j - 1] != '1' && data->cpy[i][j - 1] != '2')
		{
			data->cpy[i][j - 1] = '2';
			map_test(data, i, j - 1);
		}
		else
			map_final_check(data);
	}
}
