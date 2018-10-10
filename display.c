/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:21:18 by maxisimo          #+#    #+#             */
/*   Updated: 2018/04/13 12:14:59 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hide_legend(t_win *win)
{
	win->legend_display = (win->legend_display == ON) ? OFF : ON;
	erase(win);
}

void	put_info_to_windows(t_win *win)
{
	mlx_string_put(win->init, win->win, 1550, 35, 0xA80008, "LEGEND :");
	mlx_string_put(win->init, win->win, 1550, 60, 0xAB4A00, win->path);
	mlx_string_put(win->init, win->win, 1550, 85, 0x006962, "Zoom :");
	mlx_string_put(win->init, win->win, 1690, 85, 0x0D8C00, "'+' / '-'");
	mlx_string_put(win->init, win->win, 1550, 100, 0x006962, "move :");
	mlx_string_put(win->init, win->win, 1690, 100, 0x0D8C00, "direction arrow");
	mlx_string_put(win->init, win->win, 1550, 115, 0x006962, "rotation :");
	mlx_string_put(win->init, win->win, 1690, 115, 0x0D8C00, "'x' / 'y' / 'z'");
	mlx_string_put(win->init, win->win, 1550, 130, 0x006962, "change Z :");
	mlx_string_put(win->init, win->win, 1690, 130, 0x0D8C00,
			"'7' / '9'");
	mlx_string_put(win->init, win->win, 1550, 145, 0x006962, "Rotate :");
	mlx_string_put(win->init, win->win, 1690, 145, 0x0D8C00, "'4' / '6'");
	mlx_string_put(win->init, win->win, 1550, 160, 0x006962, "Color :");
	mlx_string_put(win->init, win->win, 1690, 160, 0x0D8C00,
			"'r' / 'g' / 'b' / 'o'");
	mlx_string_put(win->init, win->win, 1550, 175, 0x006962, "Hide legend :");
	mlx_string_put(win->init, win->win, 1690, 175, 0x0D8C00, "'tab'");
	mlx_string_put(win->init, win->win, 1550, 205, 0x006962, "Quit Fdf :");
	mlx_string_put(win->init, win->win, 1690, 205, 0x0D8C00, "'esc'");
	mlx_string_put(win->init, win->win, 1550, 190, 0x006962, "Reset :");
	mlx_string_put(win->init, win->win, 1690, 190, 0x0D8C00, "'clear'");
}
