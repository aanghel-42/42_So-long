/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:59:37 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:09:29 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_checker(int argc, char **argv, t_map *map)
{
	int				i;

	i = 0;
	map->count->coin = 0;
	map->count->exit = 0;
	map->count->player = 0;
	map->count->enemy = 0;
	if (argc < 2)
	{
		ft_printf("\x1b[31m%s\n", "ERROR - Invalid number of arguments!");
		return (0);
	}
	while (argv[1][i] != '.')
		i++;
	if (!(argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e'
			&& argv[1][i + 3] == 'r'))
	{
		ft_printf("\x1b[31m%s\n", "ERROR - Invalid exstension map!");
		return (0);
	}
	if (ft_checker_map(argv[1], map, map->count) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	map.count = malloc(sizeof(t_count));
	map.height = 0;
	i = 0;
	map.player_count = 0;
	map.coin = 0;
	if (ft_checker(argc, argv, &map) == 0)
		return (0);
	ft_creating_map(&map);
	ft_fill_xpm(&map);
	mlx_do_key_autorepeatoff(map.m);
	mlx_hook(map.w, 2, 0L, &ft_key_hook, &map);
	mlx_hook(map.w, 17, 1L << 17, &ft_exit, &map);
	mlx_loop(map.m);
	return (0);
}
