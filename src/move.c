/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:57:23 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:12:56 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_first_move_up(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		if (map->map[x][y] == COIN)
		{
			ft_character_coin(map, x, y, move);
			map->map[x][y] = PLAYER;
		}
		map->map[x][y] = PLAYER;
		ft_put_player_up(map, x, y);
		ft_put_background(map, x + 1, y);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

void	ft_first_move_down(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		if (map->map[x][y] == COIN)
		{
			ft_character_coin(map, x, y, move);
			map->map[x][y] = PLAYER;
		}
		map->map[x][y] = PLAYER;
		ft_put_player_down(map, x, y);
		ft_put_background(map, x - 1, y);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

void	ft_first_move_left(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		if (map->map[x][y] == COIN)
		{
			ft_character_coin(map, x, y, move);
			map->map[x][y] = PLAYER;
		}
		map->map[x][y] = PLAYER;
		ft_put_player_left(map, x, y);
		ft_put_background(map, x, y + 1);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

void	ft_first_move_right(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		if (map->map[x][y] == COIN)
		{
			ft_character_coin(map, x, y, move);
			map->map[x][y] = PLAYER;
		}
		map->map[x][y] = PLAYER;
		ft_put_player_right(map, x, y);
		ft_put_background(map, x, y - 1);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

int	ft_key_hook(int move, t_map *map)
{
	int		x;
	int		y;
	char	*count;

	x = map->o->p->x;
	y = map->o->p->y;
	map->dead = 0;
	map->map[x][y] = '0';
	if (ft_dead(map) == 0)
		exit(0);
	ft_key_hook_up_dw(move, map, x, y);
	ft_key_hook_sx_dx(move, map, x, y);
	if (move == KEY_E)
	{
		exit (0);
		return (0);
	}
	if (map->count->enemy > 0)
		ft_move_enemy_x(map);
	ft_put_wall(map, 0, 0);
	count = ft_itoa(map->player_count);
	mlx_string_put(map->m, map->w, 0, 0, 0xffffff, count);
	free(count);
	return (1);
}
