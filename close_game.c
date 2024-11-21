/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:46 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/01 21:03:36 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game2(t_data *data)
{
	int	i;

	i = 0;
	if (data->cpy != 0)
	{
		while (data->cpy[i])
		{
			free (data->cpy[i]);
			i++;
		}
		free (data->cpy);
	}
	if (data->img.img_floor != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collectible);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	}
	if (data->mlx_ptr != 0)
		free(data->mlx_ptr);
	exit(0);
}

void	close_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != 0)
	{
		while (data->map[i])
		{
			free (data->map[i]);
			i++;
		}
		free (data->map);
	}
	close_game2(data);
}
