/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:37:20 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:02:01 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_player_up(t_map *m, int x, int y)
{
	m->o->p_up = ft_draw_in_map(m, "Images/CRBack.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_up, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}

void	ft_put_player_left(t_map *m, int x, int y)
{
	m->o->p_left = ft_draw_in_map(m, "Images/CPL.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_left, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}

void	ft_put_player_right(t_map *m, int x, int y)
{
	m->o->p_right = ft_draw_in_map(m, "Images/CPR.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_right, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}

void	ft_put_player_down(t_map *m, int x, int y)
{
	m->o->p_down = ft_draw_in_map(m, "Images/CRFront.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_down, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}
