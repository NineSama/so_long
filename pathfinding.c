/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:58:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/23 15:15:05 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pf_replace(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == 'T')
				data->map.map[i][j] = '0';
			if (data->map.map[i][j] == 'X')
				data->map.map[i][j] = 'C';
			j++;
		}
		i++;
	}
}

void	pf_move2(t_data *data, char c, int y, int x)
{
	if (c == 'd')
	{
		if (data->map.map[y][x] == '0')
			data->map.map[y][x] = 'T';
		else if (data->map.map[y][x] == 'C')
			data->map.map[y][x] = 'X';
		y += 1;
	}
	if (c == 'r')
	{
		if (data->map.map[y][x] == '0')
			data->map.map[y][x] = 'T';
		else if (data->map.map[y][x] == 'C')
			data->map.map[y][x] = 'X';
		x += 1;
	}
}

void	pf_move(t_data *data, char c, int y, int x)
{
	if (c == 'u')
	{
		if (data->map.map[y][x] == '0')
			data->map.map[y][x] = 'T';
		else if (data->map.map[y][x] == 'C')
			data->map.map[y][x] = 'X';
		y -= 1;
	}
	if (c == 'l')
	{
		if (data->map.map[y][x] == '0')
			data->map.map[y][x] = 'T';
		else if (data->map.map[y][x] == 'C')
			data->map.map[y][x] = 'X';
		x -= 1;
	}
	pf_move2(data, c, y, x);
}

int	pf_check_exit(t_data *data, char c, int y, int x)
{
	if (c == 'u' && data->map.map[y - 1][x] == 'E')
	{
		data->pf.count_exit++;
		return (0);
	}
	if (c == 'l' && data->map.map[y][x - 1] == 'E')
	{
		data->pf.count_exit++;
		return (0);
	}
	if (c == 'd' && data->map.map[y + 1][x] == 'E')
	{
		data->pf.count_exit++;
		return (0);
	}
	if (c == 'r' && data->map.map[y][x + 1] == 'E')
	{
		data->pf.count_exit++;
		return (0);
	}
	return (1);
}

int	pf_check_next(t_data *data, char c, int y, int x)
{
	if (c == 'u' && data->map.map[y - 1][x] == 'C')
		data->pf.count_cons += 1;
	if (c == 'l' && data->map.map[y][x - 1] == 'C')
		data->pf.count_cons += 1;
	if (c == 'd' && data->map.map[y + 1][x] == 'C')
		data->pf.count_cons += 1;
	if (c == 'r' && data->map.map[y][x + 1] == 'C')
		data->pf.count_cons += 1;
	if (c == 'u' && (data->map.map[y - 1][x] == '1' || data->map.map[y - 1][x] == 'T' || data->map.map[y - 1][x] == 'X' || data->map.map[y - 1][x] == 'P'))
		return (0);
	if (c == 'l' && (data->map.map[y][x - 1] == '1' || data->map.map[y][x - 1] == 'T' || data->map.map[y][x - 1] == 'X' || data->map.map[y][x - 1] == 'P'))
		return (0);
	if (c == 'd' && (data->map.map[y + 1][x] == '1' || data->map.map[y + 1][x] == 'T' || data->map.map[y + 1][x] == 'X' || data->map.map[y + 1][x] == 'P'))
		return (0);
	if (c == 'r' && (data->map.map[y][x + 1] == '1' || data->map.map[y][x + 1] == 'T' || data->map.map[y][x + 1] == 'X' || data->map.map[y][x + 1] == 'P'))
		return (0);
	return (1);
}

int	pathfind(t_data *data, int y, int x)
{
	if (pf_check_next(data, 'r', y, x) && pf_check_exit(data, 'r', y, x))
	{
		// pf_move(data, 'r', y, x);
		if (data->pf.count_cons == data->map.count_cons && data->pf.count_exit == 1)
			return (1);
		pathfind(data, y, x + 1);
	}
	if (pf_check_next(data, 'l', y, x) && pf_check_exit(data, 'l', y, x))
	{
		// pf_move(data, 'l', y, x);
		if (data->pf.count_cons == data->map.count_cons && data->pf.count_exit == 1)
			return (1);
		pathfind(data, y, x - 1);
	}
	if (pf_check_next(data, 'u', y, x) && pf_check_exit(data, 'u', y, x))
	{
		// pf_move(data, 'u', y, x);
		if (data->pf.count_cons == data->map.count_cons && data->pf.count_exit == 1)
			return (1);
		pathfind(data, y - 1, x);
	}
	if (pf_check_next(data, 'd', y, x) && pf_check_exit(data, 'd', y, x))
	{
		// pf_move(data, 'd', y, x);
		if (data->pf.count_cons == data->map.count_cons && data->pf.count_exit == 1)
			return (1);
		pathfind(data, y + 1, x);
	}
	if (data->map.map[y][x] == '0')
			data->map.map[y][x] = 'T';
	else if (data->map.map[y][x] == 'C')
			data->map.map[y][x] = 'X';
	return (0);
}
