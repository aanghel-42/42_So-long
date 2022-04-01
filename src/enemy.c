/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:15:36 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:02:01 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_xpm_enemy(t_map *map)
{
	map->o->n = malloc(sizeof(t_c));
	map->o->e_up = "Images/wolfup.xpm";
	map->o->e_dw = "Images/wolfdw.xpm";
	map->o->e_dx = "Images/wolfdx.xpm";
	map->o->e_sx = "Images/wolfsx.xpm";
	map->o->p_d = "Images/skull.xpm";
	map->o->e_upv = ft_draw_in_map(map, map->o->e_up);
	map->o->e_dwv = ft_draw_in_map(map, map->o->e_dw);
	map->o->e_dxv = ft_draw_in_map(map, map->o->e_dx);
	map->o->e_sxv = ft_draw_in_map(map, map->o->e_sx);
	map->o->p_dead = ft_draw_in_map(map, map->o->p_d);
}

void	ft_put_e_up(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->e_upv, y * 64, x * 64);
	m->o->n->x = x;
	m->o->n->y = y;
	m->map[x][y] = 'N';
}

void	ft_put_e_dw(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->e_dwv, y * 64, x * 64);
	m->o->n->x = x;
	m->o->n->y = y;
	m->map[x][y] = 'N';
}

void	ft_put_e_dx(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->e_dxv, y * 64, x * 64);
	m->o->n->x = x;
	m->o->n->y = y;
	m->map[x][y] = 'N';
}

void	ft_put_e_sx(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->e_sxv, y * 64, x * 64);
	m->o->n->x = x;
	m->o->n->y = y;
	m->map[x][y] = 'N';
}
