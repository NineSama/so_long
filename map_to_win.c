/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:25:57 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/20 23:07:48 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	map_to_win(t_data *data, char c, int y, int x)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.ground, x * 100, y * 100);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.wall, x * 100, y * 100);
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.pers, x * 100, y * 100);
		data->pos_x = x;
		data->pos_x = y;
	}
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.exit, x * 100, y * 100);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.cons, x * 100, y * 100);
}

int	transfer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			map_to_win(data, data->map.map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (1);
}
