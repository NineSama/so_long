/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:18:58 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/16 19:04:51 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_int.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "HEHEXD");
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}