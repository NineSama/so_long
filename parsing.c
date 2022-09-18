/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:56:22 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/18 21:31:17 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     ft_strlen(char *line)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    return (i);
}

int    get_map_height(t_data *data)
{
    char    *line;
    int     i;

    i = 0;
    line = get_next_line(data->map.fd)
    while (line)
    {
        i++;
        free(line);
        line = get_next_line(data->map.fd);
    }
    data->map.height = i;
    return (i);
}

void    get_map(t_data *data)
{
    int     i;
    int     n_line;
    char    *line;

    line = get_next_line(data->map.fd);
    n_line = 0;
    i = 0;
    while (line)
    {
        data->map.map[n_line] = malloc(sizeof(char) * (ft_strlen(line) + 1));
        i = 0;
        while (line[i])
        {
            data->map.map[n_line][i] = line[i];
            i++;
            n_line++;
        }
        free(line);
        line = get_next_line(data->map.fd);
    }
}

int    initialising_map(t_data *data)
{
    if (!is_ber)
    {
        write(1, "Map not a .ber\n", 15);
        return (0);
    }
    data->map.fd = open(path, O_RDONLY);
    data->map.map = malloc(sizeof(char *) * get_map_height(data));
    get_map(data);
    return (1);
}