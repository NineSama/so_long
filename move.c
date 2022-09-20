/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:23:38 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/20 23:40:28 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_next_case(t_data *data, char c)
{
	char	i;
	
	if (data->pos_y > -1)
		i = c;
	return (1);
}

void	move_player(t_data *data, int c)
{
	if (c == 'w' && check_next_case(data, 'w'))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.ground, data->pos_x * 100, data->pos_y * 100);
		data->pos_y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.ground, data->pos_x * 100, data->pos_y * 100);		
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else if (keysym == 'w' || keysym == 'a' || keysym == 's' || keysym == 'd')
		move_player(data, keysym);
	return (0);
}

// int	handle_keyrelease(int keysym, t_data *data)
// {
	
// }
