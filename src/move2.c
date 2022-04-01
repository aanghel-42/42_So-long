/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:48:13 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:12:31 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_possible_move(t_map *map, int x, int y)
{
	if (map->map[x][y] == WALL)
		return (0);
	if (map->map[x][y] == EXIT)
	{
		if (map->count->coin == 0)
		{
			ft_put_background(map, x, y);
			map->player_count++;
			ft_printf("\nMove count: %d\n", map->player_count);
			ft_printf("\x1b[32m\n!!! You Win !!!\033[0m\n");
			exit(0);
			return (2);
		}
		else
			return (0);
	}
	return (1);
}

void	ft_move_up(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		ft_put_player_up_coin(map, x, y);
		ft_put_background(map, x + 1, y);
		if (map->map[x][y] == COIN)
			ft_character_coin(map, x, y, move);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

void	ft_move_down(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		ft_put_player_down_coin(map, x, y);
		ft_put_background(map, x - 1, y);
		if (map->map[x][y] == COIN)
			ft_character_coin(map, x, y, move);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

void	ft_move_left(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		ft_put_player_left_coin(map, x, y);
		ft_put_background(map, x, y + 1);
		if (map->map[x][y] == COIN)
			ft_character_coin(map, x, y, move);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}

void	ft_move_right(t_map *map, int x, int y, int move)
{	
	if ((ft_is_possible_move(map, x, y)) == 1)
	{
		ft_put_player_right_coin(map, x, y);
		ft_put_background(map, x, y - 1);
		if (map->map[x][y] == COIN)
			ft_character_coin(map, x, y, move);
		map->player_count++;
		ft_printf("\nMove count: %d\n", map->player_count);
	}
	return ;
}
