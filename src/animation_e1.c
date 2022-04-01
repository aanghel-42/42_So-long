/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_e1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:24:02 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 06:14:48 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_enemy_y(t_map *m)
{
	if (m->o->n->y > m->o->p->y)
	{
		if (ft_is_possible_move_e(m->map[m->o->n->x][m->o->n->y - 1]) == 1)
			ft_enemy_move_left(m);
		else
		{
			if (ft_is_possible_move_e(m->map[m->o->n->x - 1][m->o->n->y]) == 1)
				ft_enemy_move_up(m);
		}
	}
	if (m->o->n->y < m->o->p->y)
	{
		if (ft_is_possible_move_e(m->map[m->o->n->x][m->o->n->y + 1]) == 1)
			ft_enemy_move_right(m);
		else
		{
			if (ft_is_possible_move_e(m->map[m->o->n->x - 1][m->o->n->y]) == 1)
				ft_enemy_move_up(m);
		}
	}
	if (m->o->n->x == m->o->p->x && m->o->n->y == m->o->p->y)
	{
		ft_put_background(m, m->o->p->x, m->o->p->y);
		ft_put_dead_player(m, m->o->p->x, m->o->p->y);
	}
}

void	ft_put_dead_player(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->m, map->w, map->o->p_dead, y * SIZE, x * SIZE);
}

int	ft_is_possible_move_e(char c)
{
	int		i;
	char	*element;

	element = malloc(sizeof(char) * 3 + 1);
	element[0] = EXIT;
	element[1] = COIN;
	element[2] = WALL;
	element[3] = '\0';
	i = 0;
	while (element[i] != '\0')
	{
		if (element[i] == c)
		{
			free(element);
			return (0);
		}
		i++;
	}
	free(element);
	return (1);
}
