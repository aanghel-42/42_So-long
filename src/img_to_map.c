/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:32:18 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:20:30 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_xpm(t_map *map)
{
	map->o = malloc(sizeof(t_control_obj));
	map->o->w = malloc(sizeof(t_c));
	map->o->b = malloc(sizeof(t_c));
	map->o->p = malloc(sizeof(t_c));
	map->o->c = malloc(sizeof(t_c));
	map->o->ex = malloc(sizeof(t_c));
	ft_fill_xpm_enemy(map);
	map->o->w->img = "Images/wall.xpm";
	map->o->p->img = "Images/CRFront.xpm";
	map->o->c->img = "Images/mela.xpm";
	map->o->b->img = "Images/screen.xpm";
	map->o->ex->img = "Images/exit.xpm";
	map->o->wall = ft_draw_in_map(map, map->o->w->img);
	map->o->play = ft_draw_in_map(map, map->o->p->img);
	map->o->coin = ft_draw_in_map(map, map->o->c->img);
	map->o->back = ft_draw_in_map(map, map->o->b->img);
	map->o->exit = ft_draw_in_map(map, map->o->ex->img);
	ft_put_img(map);
}

void	*ft_draw_in_map(t_map *map, char *filename)
{
	int		width;
	int		height;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(map->m, filename, &width, &height);
	return (img_ptr);
}

void	ft_put_img(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	while (x < m->height)
	{
		y = 0;
		while (y < m->width)
		{
			ft_put_background(m, x, y);
			if (m->map[x][y] == '1')
				ft_put_wall(m, x, y);
			if (m->map[x][y] == 'P')
				ft_put_player(m, x, y);
			if (m->map[x][y] == 'E')
				ft_put_exit(m, x, y);
			if (m->map[x][y] == 'C')
				ft_put_coin(m, x, y);
			if (m->map[x][y] == 'N')
				ft_put_img_enemy(m, x, y);
			y++;
		}
		x++;
	}
}
