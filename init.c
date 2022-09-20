/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:08:05 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/20 22:18:56 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	initialising_imgs(t_data *data)
{
	data->image.width = 100;
	data->image.height = 100;
	data->image.ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/ground.xpm", &data->image.width, &data->image.height);
	data->image.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/wall.xpm", &data->image.width, &data->image.height);
	data->image.pers = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/pers.xpm", &data->image.width, &data->image.height);
	data->image.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/exit.xpm", &data->image.width, &data->image.height);
	data->image.cons = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/cons.xpm", &data->image.width, &data->image.height);
}

void	initialising_values(t_data *data)
{
	data->map.count_pers = 0;
	data->map.count_exit = 0;
	data->map.count_cons = 0;
	data->image.height = 0;
	data->image.width = 0;
}
