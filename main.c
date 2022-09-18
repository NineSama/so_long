/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:18:58 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/18 17:08:29 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_int.h"
#include "mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

int main(void)
{
    void    *mlx;
    void    *win_ptr;
    t_data  img;
    int     j;
    int     i;
    
    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HEHEXD");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pxl, &img.line_lenght, &img.endian);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win_ptr);
    mlx_destroy_display(mlx);
    free(mlx);
}