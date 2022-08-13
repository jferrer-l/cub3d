/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:19:41 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 07:46:54 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<math.h>
# include	<limits.h>
# include	<sys/time.h>
# include	<errno.h>
# include	"./minilibx/mlx.h"
# include	"getnextline/get_next_line.h"
// # include	"42_memleak/malloc_leak_checker.h"

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define STOP_DIR 0
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ROTLEFT 123
# define KEY_ROTRIGHT 124
# define KEY_JUMP 49
# define KEY_USE 257
# define KEY_RELOAD 15

# define ESC 53

# define TILE_SIZE  64
# define WALL_HEIGHT  64
# define PROJECTIONPLANEWIDTH  320
# define PROJECTIONPLANEHEIGHT  200
# define ROTSPEED  0.15
# define MOVSPEED  0.33

typedef struct s_data
{
	int	size_cubes;
	int	player_fov;
	int	player_height;
}				t_data;

typedef struct s_cords
{
	double		x;
	double		y;
}				t_cords;

typedef struct s_door
{
	int			x;
	int			y;
	int			state;
	int			sp_index;
	int			sp_time;
}				t_door;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_gun
{
	int			animation;
	int			num_bullets;
	int			max_bullets;
	int			sp_index;
	int			sp_time;
	t_img		img_fire[11];
	t_img		img_reload[26];
}				t_gun;

typedef struct s_player
{
	t_img		*img;
	t_cords		pos;
	t_cords		vector_view;
	double		angle_view;
	double		height;
}				t_player;

typedef struct s_minimap
{
	t_img		img;
	t_img		background;
	t_cords		pos;
	int			width;
	int			height;
	int			px_size;
	int			count_x;
	int			count_y;
	int			start_x;
	int			start_y;
	int			start_print_x;
	int			start_print_y;
}				t_minimap;

typedef struct s_mapvars
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	*ft;
	char	*ct;
	int		floor;
	int		ceiling;
}			t_mapvars;

typedef struct s_move
{
	double	start_x;
	double	start_y;
	double	new_pos_x;
	double	new_pos_y;
	double	move_vector_x;
	double	move_vector_y;
	double	dirx;
	double	diry;
}				t_move;

typedef struct s_raycast
{
	double	count;
	double	px;
	double	linex;
	double	liney;
	double	dlinex;
	double	dliney;
	double	planex;
	double	planey;
	double	walldistance;
	double	sidedistx;
	double	sidedisty;
	int		hit;
	int		side;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	int		map_x;
	int		map_y;
}				t_raycast;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	char		**map;
	t_player	hero;
	t_img		*img;
	int			map_width;
	int			map_height;
	double		fov;
	double		tile_size;
	t_raycast	ray;
	double		time;
	double		start_time;
	double		old_time;
	double		frames;
	int			backgroundx;
	t_mapvars	mapvars;
	t_minimap	minimap;
	t_gun		gun;
	int			num_doors;
	t_door		*doors;
	char		*map_name;
}				t_mlx;

int		exit_game(t_mlx *mlx);
void	free_memory_and_exit(t_mlx *mlx);
int		input(int key, t_mlx *mlx);
char	**parse_initial_map(t_mlx *mlx);
char	*get_initial_map_info(char *map_name, t_mlx *mlx);
void	check_map_valid_height_and_width(char *map_info, t_mlx *mlx);
void	check_map_is_rectangular(char *map_info, t_mlx *mlx);
void	check_map_valid_chars(char *map_info, t_mlx *mlx);
void	check_map_needed_chars(char *map_info, t_mlx *mlx);
void	check_map_surronded_by_walls(t_mlx *mlx);
int		map_is_surrounded_be_walls(t_mlx *mlx);
int		map_lines_height(char *map_info);
int		map_lines_width(char *map_info);
void	create_map_x_malloc(t_mlx *mlx, char *map_info);
char	*create_map_y_malloc(t_mlx *mlx, int count, char *map_info);
void	init_player(t_mlx *mlx);
void	init_game_data(t_mlx *mlx);
void	get_player_starting_angle(t_mlx *mlx, char angle_char);
void	get_player_starting_map_data(t_mlx *mlx);
void	draw_line(t_mlx *mlx, t_cords start_p, t_cords end_p, int ps[2]);
int		can_move_to(int x, int y, t_mlx *mlx);
void	dda(char **map, t_mlx *mlx);
void	print_line(double distance, int pixnum, t_mlx mlx);
int		load_image(t_img *slot, char *img_name, t_mlx *mlx);
void	update_direction_right(double	*dirx, double *diry, double temp);
void	update_direction_left(double *dirx, double *diry, double temp);
double	get_pend(t_mlx *mlx);
void	input_is_key_move(t_mlx *mlx, int value, int key);
int		update_route(t_mlx *mlx, int key, double *dirx, double *diry);
void	ray_set_sidedist(t_mlx *mlx);
void	ray_advance_until_hit(t_mlx *mlx);
void	ray_draw_line(int x, t_mlx *mlx);
int		free_map_memory(t_mlx *mlx);
void	move_if_needed(t_mlx *mlx);
void	check_map(t_mlx *mlx);
void	draw_cross_fire(t_mlx *mlx);
int		draw_backgroud(t_mlx *mlx);
int		render(t_mlx *mlx);
int		load_walls_images(t_mlx *mlx);
void	clean_mlx_garbage(t_mlx *mlx);
void	exit_error_get_map_name(int err_num, t_mlx *mlx);
void	exit_error_cant_open_map(t_mlx *mlx);
void	free_map_textures_vars(t_mlx *mlx);
void	exit_error_in_map_vars(int err_num, t_mlx *mlx);
void	exit_error_load_walls_images(t_mlx *mlx, int img_num);
void	exit_error_load_extra_images(t_mlx *mlx, int img_num);
void	exit_not_map_info(char *map_info, t_mlx *mlx);
void	check_have_all_map_vars(char *map_info, t_mlx *mlx);

//Marc TEST
void	raycast(t_mlx *mlx);
void	init_raycast_vars(t_mlx *mlx);
double	get_timestamp(void);
void	calcualte_fps(t_mlx *game);
void	init_mapvalidator_struct(t_mlx *mlx);
int		parse_map_vars(char *map_info, t_mlx *mlx);
char	*ft_strjoin_char(char *s1, char c);
int		is_empty_line(char *map_info, int index);
int		advance_empty_line(char *map_info, int index);
int		get_line_lenght(char *map_info, int index);
int		parse_var_no(char *map_info, int index, t_mlx *mlx);
int		parse_var_so(char *map_info, int index, t_mlx *mlx);
int		parse_var_we(char *map_info, int index, t_mlx *mlx);
int		parse_var_ea(char *map_info, int index, t_mlx *mlx);
int		parse_var_ct(char *map_info, int index, t_mlx *mlx);
int		parse_var_ft(char *map_info, int index, t_mlx *mlx);
int		parse_var_f(char *map_info, int index, t_mlx *mlx);
int		parse_var_c(char *map_info, int index, t_mlx *mlx);
void	draw_sky_background(t_mlx *mlx);
void	draw_floor_casting(t_mlx *mlx);
void	init_game_images(t_mlx *mlx);

//BONUS
void	load_minimap_image(t_mlx *mlx);
void	draw_minimap_to_screen(t_mlx *mlx);
void	load_weapon_images(t_mlx *mlx);
void	gun_fire_sprites_animation(t_mlx *mlx);
void	render_gun(t_mlx *mlx);
void	player_action_recharge(t_mlx *mlx);
void	player_action_shot(t_mlx *mlx);
void	count_doors_in_map(t_mlx *mlx);
void	init_doors(t_mlx *mlx);
void	init_doors_malloc(t_mlx *mlx);
void	render_doors(t_mlx *mlx);
void	player_action_use(t_mlx *mlx);
void	open_door(t_mlx *mlx, int x, int y);
void	clean_bonus_extra_imgs(t_mlx *mlx);
int		walkable(int x, int y, t_mlx *mlx);
void	calculate_move_vars(t_mlx *mlx, t_move *mv);
void	check_and_move(t_mlx *mlx, t_move *mv);
void	draw_in_minimap_img_px_in_size(int x, int y, unsigned long color,
			t_mlx *mlx);
void	draw_minimap_image_color_background(t_mlx *mlx);
void	draw_player_in_minimap(t_mlx *mlx);

void	check_leaks(void); //LEAKS esto hay que quitarlo en el futuro

#endif
