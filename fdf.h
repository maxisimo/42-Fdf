/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:22:08 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/17 10:01:42 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "keys.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# define WIN_H 1500
# define WIN_W 1900

# define BROWN 0x6D2B00
# define GREEN1 0x25FF50
# define WHITE 0xD5D5D5
# define BLUE1 0x594DEC
# define BLUE2 0x0032A4
# define BLUE3 0x080163
# define BLUE4 0x6092E5
# define RED1 0xF50000
# define RED2 0x990000
# define YELLOW 0xEC8800
# define ORANGE 0xEC6200
# define GREEN2 0x0E4E00
# define GREEN3 0x2C7600
# define ORIGIN 0
# define RED 1
# define GREEN 2
# define BLUE 3
# define OFF 0
# define ON 1
# define DRAW 1
# define ROT_X 0
# define ROT_Y 1
# define ROT_Z 2

typedef struct	s_point
{
	int			d3x;
	int			d3y;
	int			d3z;
	int			d2x;
	int			d2y;
	int			color;
}				t_point;

typedef struct	s_win
{
	void		*init;
	void		*win;
	char		*data;
	void		*img;
	int			size;
	int			endian;
	int			color;
	int			ccolor;
	t_point		**map;
	char		*path;
	int			rot;
	int			map_w;
	int			map_h;
	int			max_z;
	int			legend_display;
	float		angle;
	int			zoom;
	int			move_lr;
	int			move_ud;
	int			val_z;
}				t_win;

typedef struct	s_bresenham
{
	int			delta_x;
	int			sign_x;
	int			delta_y;
	int			sign_y;
	int			delta_error;
}				t_bres;

typedef struct	s_rotate_point
{
	float		x;
	float		y;
	float		z;
	float		px;
	float		py;
	float		pz;
}				t_rp;

int				count_map_length(char **str);
int				len_tab(char *argv);
t_point			*create_int_table(t_win *win, char *str, int pos);
t_point			**create_map(t_win *win);
t_point			ft_create_point(char *str, int x, int y);
void			default_values(t_win *win);
int				key_hook(int keycode, t_win *win);
int				key_hook2(int keycode, t_win *win);
int				expose_hook(t_win *win);
void			calcule_coord(t_win *win);
void			calculate(t_win *win, t_point *point);
int				fdf_color(int p1, int p2, int max);
int				red_color(int p1, int p2, int max);
int				green_color(int p1, int p2, int max);
int				blue_color(int p1, int p2, int max);
void			draw_map(t_win *win);
void			draw_line(t_win *win, t_point *pt1, t_point *pt2);
t_bres			*bres_constr(t_point *pt1, t_point *pt2, int max, t_win *win);
void			free_lst(char **array);
void			draw_point(t_win *win, int x, int y, int color);
void			zoom_map(t_win *win);
void			de_zoom_map(t_win *win);
void			move_image_up(t_win *win);
void			move_image_down(t_win *win);
void			move_image_left(t_win *win);
void			move_image_right(t_win *win);
void			change_origin(t_win *win);
void			change_red(t_win *win);
void			change_green(t_win *win);
void			change_blue(t_win *win);
void			increase_height(t_win *win);
void			decrease_height(t_win *win);
void			erase(t_win *win);
void			reset(t_win *win);
void			rotate_left(t_win *win);
void			rotate_right(t_win *win);
void			pivote_z(t_win *win);
void			pivote_y(t_win *win);
void			pivote_x(t_win *win);
int				check_x(t_win *win, int x);
int				check_y(t_win *win, int y);
int				crt_x(t_win *win, int x);
int				crt_y(t_win *win, int y);
int				ft_abs(int nb);
int				len_for_zoom(char *str);
void			calcule_rotation(t_win *win, t_point *point);
void			put_info_to_windows(t_win *win);
void			hide_legend(t_win *win);

#endif
