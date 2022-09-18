/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:23:45 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/18 21:37:00 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# define A_KEY			97
# define W_KEY			119
# define S_KEY			115
# define D_KEY			100
# define ESC			65307

typedef struct  s_map
{
    int     fd;
    char    **map;
    int     height;
    int     cons;
    int     ground;
    int     wall;
    int     pers;
    int     exit;
}               t_map;

typedef struct  s_img
{
    int img_width;
    int img_height;
}               t_img;

typedef struct  s_data
{
    t_img   img;
    t_map   map;
}               t_data;

#endif