/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:23:45 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/20 23:38:49 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "get_next_line.h"
# include <X11/X.h>
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
	int     width;
	int		count_cons;
	int		count_pers;
	int		count_exit;

}               t_map;

typedef struct  s_image
{
	int 	width;
	int 	height;
	void	*cons;
	void	*ground;
	void	*wall;
	void	*pers;
	void	*exit;
}               t_image;

typedef struct  s_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	char	*path;
	int		pos_x;
	int		pos_y;
	t_image  image;
	t_map   map;
}               t_data;

/* utils.c */
int	ft_strlen(char *line);

/* valid.c */
int		is_rectangle(t_data *data);
int		is_surrounded(t_data *data);
int		is_good_amount(t_data *data);
int		count_amount(t_data *data);
int		is_valid(t_data *data);

/* parsing.c */
void	get_map(t_data *data);
int		get_map_height(t_data *data);
int		create_map(t_data *data);

/* map_to_win */
void    map_to_win(t_data *data, char c, int y, int x);
int		transfer(t_data *data);

/* init.c */
void	initialising_values(t_data *data);
void	initialising_imgs(t_data *data);

/* move.c */
int		check_next_case(t_data *data, char c);
void	move_player(t_data *data, int c);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
#endif