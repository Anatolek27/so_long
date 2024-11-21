/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:26:40 by akunegel          #+#    #+#             */
/*   Updated: 2023/12/05 16:37:52 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *error, t_data *data)
{
	write(1, error, ft_strlen(error));
	close_game(data);
	return (1);
}

void	init_content(t_data *data)
{
	data->content.exit = 'E';
	data->content.player = 'P';
	data->content.collectible = 'C';
	data->content.floor = '0';
	data->content.wall = '1';
	data->content.count_e = 0;
	data->content.count_p = 0;
	data->content.count_c = 0;
	data->count = 0;
	data->content.collected = 0;
	data->error = 0;
}

void	get_dimensions(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	width = ft_strlen(data->map[0]);
	while (data->map[height])
		height++;
	data->width = width;
	data->height = height;
}

void	map_cpy(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->cpy = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->cpy)
		exit(1);
	while (data->map[i])
	{
		j = 0;
		data->cpy[i] = (char *)malloc(sizeof(char) * (data->width + 1));
		if (!data->cpy[i])
			exit(1);
		while (data->map[i][j])
		{
			data->cpy[i][j] = data->map[i][j];
			j++;
		}
		data->cpy[i][j] = '\0';
		i++;
	}
	data->cpy[i] = 0;
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (argc != 2)
		return (ft_error("Expecting 1 argument.\n", &data));
	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b'
	|| argv[1][i - 3] != '.')
		return (ft_error("Argument not of type .ber\n", &data));
	data.mlx_ptr = mlx_init();
	data.map = get_map(argv[1], &data);
	init_content(&data);
	get_dimensions(&data);
	first_scan(&data);
	map_cpy(&data);
	scan_errors(&data);
	if (data.map != NULL)
		render_movements(&data);
	else
		close_game(&data);
	return (0);
}
