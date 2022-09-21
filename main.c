/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:18:58 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/21 17:30:36 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_int.h"
#include "mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

#	define WINDOW_WIDTH 1000
#	define WINDOW_HEIGHT 1000

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		write(2, "Not 2 args\n", 11);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (2);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "HEHEXD");
	if (!data->win_ptr)
		return (3);
	data->path = av[1];
	if (!create_map(data))
		return (4);
	transfer(data);
	mlx_loop_hook(data->mlx_ptr, &transfer, data);//proeger mlx et free
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);//proeger mlx et free
	// mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_loop(data->mlx_ptr);//proeger mlx et free
	return (0);
}
