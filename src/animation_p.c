/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:57:46 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 06:03:02 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_character_coin(t_map	*map, int x, int y, int move)
{
	if (move == KEY_W || move == KEY_A_U)
	{
		ft_put_background(map, x, y);
		ft_put_player_up_coin(map, x, y);
		map->coin = map->count->coin--;
	}
	else if (move == KEY_S || move == KEY_A_D)
	{
		ft_put_background(map, x, y);
		ft_put_player_down_coin(map, x, y);
		map->coin = map->count->coin--;
	}
	else if (move == KEY_A || move == KEY_A_L)
	{
		ft_put_background(map, x, y);
		ft_put_player_left_coin(map, x, y);
		map->coin = map->count->coin--;
	}
	else if (move == KEY_D || move == KEY_A_R)
	{
		ft_put_background(map, x, y);
		ft_put_player_right_coin(map, x, y);
		map->coin = map->count->coin--;
	}
	map->player_count--;
}
