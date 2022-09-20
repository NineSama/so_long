/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:56:22 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/20 21:16:34 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(data->map.fd);
	data->map.width = ft_strlen(line) - 1;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.height = i;
	return (i);
}

void	get_map(t_data *data)
{
	int		i;
	int		n_line;
	char	*line;

	data->map.fd = open(data->path, O_RDONLY);
	line = get_next_line(data->map.fd);
	n_line = 0;
	i = 0;
	while (line)
	{
		data->map.map[n_line] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			data->map.map[n_line][i] = line[i];
			i++;
		}
		data->map.map[n_line][i] = '\0';
		n_line++;
		free(line);
		line = get_next_line(data->map.fd);
	}
}

int	is_ber(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i] && data->path[i] != '.')
		i++;
	if (data->path[i] == '.' && data->path[i + 1] == 'b'
		&& data->path[i + 2] == 'e' && data->path[i + 3] == 'r'
		&& data->path[i + 4] == '\0')
		return (1);
	return (0);
}

int	create_map(t_data *data)
{
	if (!is_ber(data))
	{
		write(2, "Map not a .ber\n", 15);
		return (0);
	}
	data->map.fd = open(data->path, O_RDONLY);
	if (!data->map.fd)
		return (0);
	data->map.map = malloc(sizeof(char *) * get_map_height(data));
	if (!data->map.map)
		return (0);
	initialising_values(data);
	initialising_imgs(data);
	get_map(data);
	return (is_valid(data));
}
