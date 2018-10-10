/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:48:00 by maxisimo          #+#    #+#             */
/*   Updated: 2018/04/09 14:21:13 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_image_up(t_win *win)
{
	win->move_ud -= 10;
	erase(win);
}

void	move_image_down(t_win *win)
{
	win->move_ud += 10;
	erase(win);
}

void	move_image_left(t_win *win)
{
	win->move_lr -= 10;
	erase(win);
}

void	move_image_right(t_win *win)
{
	win->move_lr += 10;
	erase(win);
}
