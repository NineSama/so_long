/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:25:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/18 21:52:42 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int is_rectangle(t_data *data)
{
    int standard;
    int i;
    int j;
    
    standard = ft_strlen(data->map.map[0]);
    i = 0;
    while (i < data->map.height)
    {
        j = 0;
        if (i == data->map.height - 1)
            standard--;
        while (data->map.map[i][j])
            j++;
        if (j != standard)
            return (0);
        i++;
    }
    return (1);
}

int is_surrounded(t_data *data)
{
    int i;
    int j;
    int standard;
    
    standard = ft_strlen(data->map.map[0]) - 1;
    i = 0;
    while (i < data->map.height)
    {
        j = 0;
        if (i == data->map.height - 1)
            standard--;
        while (data->map.map[i][j])
        {

            if ((i == 0 || i == height -1) && data->map.map[i][j] != '1')
                return (0);
            if (data->map.map[i][0] != 1 || data->map.map[i][standard] != '1')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_good_amount(t_data *data)
{
    
}