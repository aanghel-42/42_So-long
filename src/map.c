/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:58 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:28:19 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_matrix(t_map *map)
{
	int	x;
	int	s;
	int	y;

	x = 0;
	y = 0;
	s = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			map->map[x][y] = map->max_line[s];
			s++;
			y++;
		}
		x++;
	}
	free(map->max_line);
}

void	ft_creating_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char) * map->height * map->width);
	if (!map->map)
		return ;
	while (i <= map->height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->width);
		if (!map->map[i])
		{
			free(map->map);
			return ;
		}
		i++;
	}
	ft_fill_matrix(map);
	map->m = mlx_init();
	map->w = mlx_new_window(map->m, (map->width - 1) * 64, \
					map->height * 64, "So Long");
}
