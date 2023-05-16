/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:13:46 by nmascrie          #+#    #+#             */
/*   Updated: 2023/05/09 11:13:47 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 900
# define MLX_ERROR 1

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

# define IMAGE_SIZE 64

# ifndef X_SPAWN
#  define X_SPAWN 1
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_imgset
{
	void	*wall;
	void	*floor;
	void	*door_locked;
	void	*door_open;
	void	*coin;
	void	*coin_b;
	void	*coin_c;
	void	*coin_d;
	void	*hero_up[3];
	void	*hero_down[3];
	void	*hero_left[3];
	void	*hero_right[3];
	void	*mr_x[4];
	void	*hero_happy;
	void	*hero_dead;
	int		h;
	int		w;
}	t_imgset;

typedef struct s_data
{
	int			dir;
	int			chase;
	int			coins;
	int			*coin_pos;
	int			score;
	int			prog;
	int			width;
	int			height;
	int			win;
	int			frame;
	t_point		exit;
	t_img		img;
	t_imgset	set;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_point		*pos;
	t_point		*mr_x;
}	t_data;

extern int	g_anim_frame;

int		dest_win(t_data *data);
int		move(int dir, t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		is_coin(int x, int y, t_data *data);
int		render(t_data *data);
int		find_coins(char **data);
int		check_format(char **map);
int		check_chars(char **map);
int		check_io(char **map);
int		check_walls(char **map);
int		check_paths(char **map);
int		count_lines(char **map);
int		print_error(char *msg);

t_point	find_character(t_data *data);
t_point	find_exit(t_data *data);

void	update_score(t_data *data);
void	generate_coins_pos(t_data *data);
void	progress_bar(t_data *data);
void	progress_steps(t_data *data);
void	progress_percent(t_data *data);
void	load_images(t_data *data);
void	print_image(t_data *data, void *img, int x, int y);
void	print_victory(t_data *data, void *img, int x, int y);
void	progress_error(t_data *data, int show);
void	free_all(t_data *data);
void	transition(t_data *data, int color);
void	rect(t_data *data);
void	start(t_data *data, char **t);
void	calculate_window_size(t_data *data);
void	render_mainchar(t_data *data, int j, int i);
void	render_coin(t_data *data, int j, int i);
void	render_background(t_data *data, int j, int i, char c);
void	render_loop(t_data *data, int i, int j);
void	victory_checker(t_data *data);
void	free_map(t_data *data);
void	free_map_no_launch(char **data);

char	**read_map(char *path);

#endif
