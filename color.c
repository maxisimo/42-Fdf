/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:34:59 by maxisimo          #+#    #+#             */
/*   Updated: 2018/03/19 13:43:22 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_blue(t_win *win)
{
	win->ccolor = BLUE;
	erase(win);
}

void	change_origin(t_win *win)
{
	win->ccolor = ORIGIN;
	erase(win);
}

void	change_red(t_win *win)
{
	win->ccolor = RED;
	erase(win);
}

void	change_green(t_win *win)
{
	win->ccolor = GREEN;
	erase(win);
}
