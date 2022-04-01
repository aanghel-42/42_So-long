/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 05:06:19 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 03:33:29 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_enemy_move_right(t_map *map)
{
	map->map[map->o->n->x][map->o->n->y] = '0';
	map->map[map->o->n->x][map->o->n->y + 1] = 'N';
	ft_put_background(map, map->o->n->x, map->o->n->y);
	ft_put_e_dx(map, map->o->n->x, map->o->n->y + 1);
	return (0);
}

int	ft_enemy_move_down(t_map *map)
{
	map->map[map->o->n->x][map->o->n->y] = '0';
	map->map[map->o->n->x + 1][map->o->n->y] = 'N';
	ft_put_background(map, map->o->n->x, map->o->n->y);
	ft_put_e_dw(map, map->o->n->x + 1, map->o->n->y);
	return (0);
}

int	ft_enemy_move_left(t_map *map)
{
	map->map[map->o->n->x][map->o->n->y] = '0';
	map->map[map->o->n->x][map->o->n->y - 1] = 'N';
	ft_put_background(map, map->o->n->x, map->o->n->y);
	ft_put_e_sx(map, map->o->n->x, map->o->n->y - 1);
	return (0);
}

int	ft_enemy_move_up(t_map *map)
{
	map->map[map->o->n->x][map->o->n->y] = '0';
	map->map[map->o->n->x - 1][map->o->n->y] = 'N';
	ft_put_background(map, map->o->n->x, map->o->n->y);
	ft_put_e_up(map, map->o->n->x - 1, map->o->n->y);
	return (0);
}

void	ft_move_enemy_x(t_map *m)
{
	if (m->o->n->x < m->o->p->x)
	{
		if (ft_is_possible_move_e(m->map[m->o->n->x + 1][m->o->n->y]) == 1)
			ft_enemy_move_down(m);
		else
			ft_move_enemy_y(m);
	}
	else if (m->o->n->x == m->o->p->x && m->o->n->y == m->o->p->y)
	{
		ft_put_background(m, m->o->p->x, m->o->p->y);
		ft_put_dead_player(m, m->o->p->x, m->o->p->y);
	}
	else if (m->o->n->x == m->o->p->x)
		ft_move_enemy_y(m);
	else if (m->o->n->x > m->o->p->x)
	{
		if (ft_is_possible_move_e(m->map[m->o->n->x - 1][m->o->n->y]) == 1)
			ft_enemy_move_up(m);
		else
			ft_move_enemy_y(m);
	}
}
