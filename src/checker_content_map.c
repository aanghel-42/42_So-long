/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_content_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:53:16 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 06:18:51 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_lateral_walls(t_map *map, int k)
{
	int	j;

	j = 2;
	while (j <= map->height)
	{
		if (map->max_line[map->width * j - 2] != '1')
		{
			ft_printf("\x1b[31m%s\n", "ERROR - The last colum isn't all walls!");
			return (0);
		}
		j++;
	}
	j = 1;
	while (j < map->height)
	{
		if (map->max_line[(k + 1) - (map->width * j)] != '1')
		{
			ft_printf("\x1b[31m%s\n", "ERROR - The first colum isn't all walls!");
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_check_maps_walls(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->max_line[++i] != '\n')
	{
		if (map->max_line[i] != '1')
		{
			ft_printf("\x1b[31m%s\n", "ERROR - The first row isn't all walls!");
			return (0);
		}
	}
	k = map->width * map->height - 2;
	while (map->max_line[k] != '\n')
	{
		if (map->max_line[k] != '1')
		{
			ft_printf("\x1b[31m%s\n", "ERROR - The last row isn't all walls!");
			return (0);
		}
		k--;
	}
	if (ft_check_lateral_walls(map, k) == 0)
		return (0);
	return (1);
}

int	ft_count_element(t_count *obj)
{
	if (obj->player != 1)
	{
		ft_printf("\x1b[31m%s\n", "ERROR - Too many players!");
		return (0);
	}
	if (obj->coin < 1)
	{
		ft_printf("\x1b[31m%s\n", "ERROR - Problem with collectible!");
		return (0);
	}
	if (obj->exit < 1)
	{
		ft_printf("\x1b[31m%s\n", "ERROR - Problem with exit!");
		return (0);
	}
	if (obj->enemy > 1)
	{
		ft_printf("\x1b[31m%s\n", "ERROR - Problem with enemy!");
		return (0);
	}
	return (1);
}

int	ft_content_map(t_map *map, t_count *obj)
{
	int	i;

	i = -1;
	while (map->max_line[++i] != '\0')
	{
		if (map->max_line[i] == PLAYER)
			obj->player++;
		else if (map->max_line[i] == EXIT)
			obj->exit++;
		else if (map->max_line[i] == COIN)
		{
			obj->coin++;
			map->coin++;
		}
		else if (map->max_line[i] == 'N')
			obj->enemy++;
		else if (!(map->max_line[i] == '1' || map->max_line[i] == '0'
				|| map->max_line[i] == '\n'))
		{
			ft_printf("\x1b[31m%s\n", "ERROR - Found character not allowed!");
			return (0);
		}
	}
	return (1);
}
