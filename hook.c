/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:32:51 by maxisimo          #+#    #+#             */
/*   Updated: 2018/04/13 12:04:17 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_win *win)
{
	calcule_coord(win);
	mlx_put_image_to_window(win->init, win->win, win->img, 0, 0);
	if (win->legend_display)
		put_info_to_windows(win);
	return (0);
}

int		key_hook(int keycode, t_win *win)
{
	if (keycode == ZOOM)
		zoom_map(win);
	if (keycode == DEZOOM)
		de_zoom_map(win);
	if (keycode == MVUP)
		move_image_up(win);
	if (keycode == MVDWN)
		move_image_down(win);
	if (keycode == MVL)
		move_image_left(win);
	if (keycode == MVR)
		move_image_right(win);
	if (keycode == RES)
		reset(win);
	if (keycode == HLEG)
		hide_legend(win);
	key_hook2(keycode, win);
	return (0);
}

int		key_hook2(int keycode, t_win *win)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RTL)
		rotate_left(win);
	if (keycode == RTR)
		rotate_right(win);
	if (keycode == PVZ)
		pivote_z(win);
	if (keycode == PVY)
		pivote_y(win);
	if (keycode == PVX)
		pivote_x(win);
	if (keycode == 11)
		change_blue(win);
	if (keycode == 15)
		change_red(win);
	if (keycode == 5)
		change_green(win);
	if (keycode == 31)
		change_origin(win);
	if (keycode == 92)
		increase_height(win);
	if (keycode == 89)
		decrease_height(win);
	return (0);
}
