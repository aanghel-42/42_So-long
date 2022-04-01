/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:54:09 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 07:28:27 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "./mlx/mlx.h"
# include <mlx.h>
# include "./PRINTF/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

# define RED "\x1b[31m"
# define SIZE	64
//Keys
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_E	53
# define KEY_A_U 126 
# define KEY_A_D 125
# define KEY_A_L 123
# define KEY_A_R 124
//Personaggi
# define PLAYER	'P'
# define EXIT	'E'
# define COIN	'C'
# define EMPTY  '0'
# define WALL	'1'
# define ENEMY	'N'

typedef struct s_count
{
	int	player;
	int	coin;
	int	exit;
	int	enemy;
}	t_count;

typedef struct s_c
{
	int		x;
	int		y;
	char	*img;
}	t_c;

typedef struct s_control_obj
{
	t_c		*p;
	t_c		*c;
	t_c		*w;
	t_c		*b;
	t_c		*ex;
	t_c		*n;
	char	*e_up;
	char	*e_dw;
	char	*e_sx;
	char	*e_dx;
	char	*p_d;
	void	*e_upv;
	void	*e_dwv;
	void	*e_sxv;
	void	*e_dxv;
	void	*wall;
	void	*p_dead;
	void	*play;
	void	*coin;
	void	*exit;
	void	*back;
	void	*p_up;
	void	*p_left;
	void	*p_right;
	void	*p_down;
	void	*p_up_coin;
	void	*p_down_coin;
	void	*p_left_coin;
	void	*p_right_coin;
}	t_control_obj;

typedef struct s_map
{
	int				height;
	int				width;
	int				dead;
	int				coin;
	int				player_count;
	int				up;
	int				dw;
	int				dx;
	int				sx;
	char			*max_line;
	char			**map;
	void			*m;
	void			*w;
	t_control_obj	*o;
	t_count			*count;
}	t_map;
//pos_enemy.c
int		ft_dead(t_map *map);
void	ft_put_img_enemy(t_map	*map, int x, int y);
void	ft_put_img_enemy_norma(t_map *map, int x, int y);

//enemy.c
void	ft_fill_xpm_enemy(t_map *map);
void	ft_put_e_up(t_map *m, int x, int y);
void	ft_put_e_dw(t_map *m, int x, int y);
void	ft_put_e_dx(t_map *m, int x, int y);
void	ft_put_e_sx(t_map *m, int x, int y);

//animation_e1.c
int		ft_is_possible_move_e(char c);
void	ft_move_enemy_y(t_map *m);
void	ft_put_dead_player(t_map *map, int x, int y);

//animation_e.c
int		ft_enemy_move_left(t_map *map);
int		ft_enemy_move_up(t_map *map);
int		ft_enemy_move_down(t_map *map);
int		ft_enemy_move_right(t_map *map);
void	ft_move_enemy_x(t_map *m);

//animation_p.c
void	ft_character_coin(t_map *map, int x, int y, int move);

//move_character.c
void	ft_put_player_left_coin(t_map *m, int x, int y);
void	ft_put_player_right_coin(t_map *m, int x, int y);
void	ft_put_player_down_coin(t_map *m, int x, int y);
void	ft_put_player_up_coin(t_map *m, int x, int y);
//move_character.c
void	ft_put_player_up(t_map *m, int x, int y);
void	ft_put_player_left(t_map *m, int x, int y);
void	ft_put_player_right(t_map *m, int x, int y);
void	ft_put_player_down(t_map *m, int x, int y);

//utils.c
size_t	ft_strlen(char *s);
size_t	find_newline(char *s);
int		ft_exit(void);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

//move.c
int		ft_key_hook(int move, t_map *map);
void	ft_first_move_up(t_map *map, int x, int y, int move);
void	ft_first_move_down(t_map *map, int x, int y, int move);
void	ft_first_move_left(t_map *map, int x, int y, int move);
void	ft_first_move_right(t_map *map, int x, int y, int move);

//move2.c
int		ft_is_possible_move(t_map *map, int x, int y);
void	ft_move_up(t_map *map, int x, int y, int move);
void	ft_move_down(t_map *map, int x, int y, int move);
void	ft_move_left(t_map *map, int x, int y, int move);
void	ft_move_right(t_map *map, int x, int y, int move);

//move3.c
void	ft_key_hook_up_dw(int move, t_map *map, int x, int y);
void	ft_key_hook_sx_dx(int move, t_map *map, int x, int y);

//map.c
void	ft_fill_matrix(t_map *map);
void	ft_creating_map(t_map *map);

//main.c
int		ft_checker(int argc, char **argv, t_map *map);

//img_to_map.c
void	ft_fill_xpm(t_map *map);
void	*ft_draw_in_map(t_map *map, char *filename);
void	ft_put_img(t_map *map);

//img_to_map2.c
void	ft_put_wall(t_map *m, int x, int y);
void	ft_put_coin(t_map *m, int x, int y);
void	ft_put_exit(t_map *m, int x, int y);
void	ft_put_player(t_map *m, int x, int y);
void	ft_put_background(t_map *m, int x, int y);

//checker_map.c
char	*ft_get_next_line(int fd);
int		ft_hight_matrix(t_map *map, char *line);
int		ft_width_matrix(int file, t_map *map);
int		ft_checker_map(const char *file, t_map *map, t_count *obj);

//checker_content_map.c
int		ft_check_lateral_walls(t_map *map, int k);
int		ft_check_maps_walls(t_map *map);
int		ft_content_map(t_map *map, t_count *obj);
int		ft_count_element(t_count *obj);

//libft.c
int		ft_len(int n);
int		ft_abs(int n);
char	*ft_itoa(int n);

#endif