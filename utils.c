/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:01:49 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/21 17:19:40 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	destroy_images(t_data *data)
{
	if (data->image.cons)
		mlx_destroy_image(data->mlx_ptr, data->image.cons);
	if (data->image.pers_left)
		mlx_destroy_image(data->mlx_ptr, data->image.pers_left);
	if (data->image.pers_right)
		mlx_destroy_image(data->mlx_ptr, data->image.pers_right);
	if (data->image.wall)
		mlx_destroy_image(data->mlx_ptr, data->image.wall);
	if (data->image.ground)
		mlx_destroy_image(data->mlx_ptr, data->image.ground);
	if (data->image.exit)
		mlx_destroy_image(data->mlx_ptr, data->image.exit);
}

void	free_all(t_data *data, char c)
{
	int	i;
	
	i = 0;
	if (c == 't')
	{
		while (i < data->map.height)
		{
			free(data->map.map[i]);
			i++;
		}
	}
	free(data->map.map);
	destroy_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}