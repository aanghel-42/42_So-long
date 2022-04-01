/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:28:26 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/24 02:22:25 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_wall(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->wall, y * 64, x * 64);
}

void	ft_put_coin(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->coin, y * 64, x * 64);
}

void	ft_put_exit(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->exit, y * 64, x * 64);
}

void	ft_put_player(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->play, y * 64, x * 64);
	m->o->p->x = x;
	m->o->p->y = y;
}

void	ft_put_background(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->m, m->w, m->o->back, y * 64, x * 64);
}
