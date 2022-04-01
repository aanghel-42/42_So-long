/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:01:07 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:02:01 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_player_up_coin(t_map *m, int x, int y)
{
	m->o->p_up_coin = ft_draw_in_map(m, \
						"Images/CRBack3.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_up_coin, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}

void	ft_put_player_left_coin(t_map *m, int x, int y)
{
	m->o->p_left_coin = ft_draw_in_map(m, \
							"Images/CPL3.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_left_coin, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}

void	ft_put_player_right_coin(t_map *m, int x, int y)
{
	m->o->p_right_coin = ft_draw_in_map(m, \
							"Images/CPR3.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_right_coin, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}

void	ft_put_player_down_coin(t_map *m, int x, int y)
{
	m->o->p_down_coin = ft_draw_in_map(m, \
						"Images/CRFront3.xpm");
	mlx_put_image_to_window(m->m, m->w, m->o->p_down_coin, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
	m->map[x][y] = PLAYER;
}
