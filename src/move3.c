/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:01:19 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/24 00:51:24 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_key_hook_up_dw(int move, t_map *map, int x, int y)
{
	if (move == KEY_W || move == KEY_A_U)
	{
		if (map->coin == map->count->coin)
			ft_first_move_up(map, (x - 1), y, move);
		if (map->coin != map->count->coin)
			ft_move_up(map, (x - 1), y, move);
	}
	if (move == KEY_S || move == KEY_A_D)
	{
		if (map->coin == map->count->coin)
			ft_first_move_down(map, (x + 1), y, move);
		if (map->coin != map->count->coin)
			ft_move_down(map, (x + 1), y, move);
	}
}

void	ft_key_hook_sx_dx(int move, t_map *map, int x, int y)
{
	if (move == KEY_A || move == KEY_A_L)
	{
		if (map->coin == map->count->coin)
			ft_first_move_left(map, x, (y - 1), move);
		if (map->coin != map->count->coin)
			ft_move_left(map, x, (y - 1), move);
	}
	if (move == KEY_D || move == KEY_A_R)
	{
		if (map->coin == map->count->coin)
			ft_first_move_right(map, x, (y + 1), move);
		if (map->coin != map->count->coin)
			ft_move_right(map, x, (y + 1), move);
	}
}
