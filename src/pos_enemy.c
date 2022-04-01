/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 03:23:56 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 06:25:53 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img_enemy(t_map	*map, int x, int y)
{
	map->up = map->map[x - 1][y];
	map->dw = map->map[x + 1][y];
	map->dx = map->map[x][y + 1];
	map->sx = map->map[x][y - 1];
	ft_put_img_enemy_norma(map, x, y);
	if (map->up == WALL && map->dx == WALL && map->dw == WALL)
		ft_put_e_sx(map, x, y);
	else if (map->up == WALL && map->sx == WALL && map->dw == WALL)
		ft_put_e_dx(map, x, y);
	else if (map->dw == WALL && map->dx == WALL)
		ft_put_e_sx(map, x, y);
	else if (map->dw == WALL && map->sx == WALL)
		ft_put_e_dx(map, x, y);
	else if (map->up == WALL && map->sx == WALL)
		ft_put_e_dx(map, x, y);
	else if (map->up == WALL && map->dx == WALL)
		ft_put_e_sx(map, x, y);
	else if (map->dw == WALL)
		ft_put_e_dx(map, x, y);
	else if (map->up == WALL)
		ft_put_e_dx(map, x, y);
	else if (map->sx == WALL)
		ft_put_e_dx(map, x, y);
	else if (map->dx == WALL)
		ft_put_e_sx(map, x, y);
}

void	ft_put_img_enemy_norma(t_map *map, int x, int y)
{
	x = map->o->n->x;
	y = map->o->n->y;
	if (map->up == '0' && map->dx == '0' && map->dw == '0' \
							&& map->sx == '0')
		ft_put_e_dx(map, x, y);
	else if (map->up == 'N' || map->dw == 'N')
		ft_put_e_dx(map, x, y);
	else if (map->dx == 'N')
		ft_put_e_sx(map, x, y);
	else if (map->sx == 'N')
		ft_put_e_dx(map, x, y);
}

int	ft_dead(t_map *map)
{
	if ((map->o->n->x == map->o->p->x) && (map->o->n->y == map->o->p->y))
	{
		ft_put_background(map, map->o->p->x, map->o->p->y);
		ft_put_dead_player(map, map->o->p->x, map->o->p->y);
		ft_printf("\x1b[31m\n!!! GAME OVER !!!\033[0m\n");
		return (0);
	}
	return (1);
}
