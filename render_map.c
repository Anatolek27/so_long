/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:30:50 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:30:50 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_data *data)
{
	data->img.floor = "images/blue.xpm";
	data->img.player = "images/shrek.xpm";
	data->img.exit = "images/exit.xpm";
	data->img.wall = "images/wall.xpm";
	data->img.collectible = "images/fiona.xpm";
	data->img.height = 60;
	data->img.width = 60;
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collectible, &(data->img.width), &(data->img.height));
}

void	put_image(int x, int y, char c, t_data *data)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_wall, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_floor, x, y);
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_collectible, x, y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_floor, x, y);
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_player, x, y);
	}
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_exit, x, y);
	else
		mlx_put_image_to_window(data->mlx_ptr,
			data->mlx_win, data->img.img_floor, x, y);
}

int	map_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_image(j * 60, i * 60, data->map[i][j], data);
			j++;
		}
		i++;
	}
	return (0);
}
