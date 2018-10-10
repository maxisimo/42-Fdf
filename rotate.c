/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 09:51:17 by maxisimo          #+#    #+#             */
/*   Updated: 2018/04/15 09:51:20 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_left(t_win *win)
{
	win->angle += 0.05;
	erase(win);
}

void	rotate_right(t_win *win)
{
	win->angle -= 0.05;
	erase(win);
}

void	pivote_z(t_win *win)
{
	win->rot = ROT_Z;
	erase(win);
}

void	pivote_y(t_win *win)
{
	win->rot = ROT_Y;
	erase(win);
}

void	pivote_x(t_win *win)
{
	win->rot = ROT_X;
	erase(win);
}
