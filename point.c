/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:14:06 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/17 10:02:13 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_x(t_win *win, int x)
{
	if ((x + win->move_lr) < WIN_W && (x + win->move_lr) > 0)
		return (1);
	return (0);
}

int			check_y(t_win *win, int y)
{
	if ((y + win->move_ud) < WIN_H && (y + win->move_ud) > 0)
		return (1);
	return (0);
}

int			crt_x(t_win *win, int x)
{
	return (x + win->move_lr);
}

int			crt_y(t_win *win, int y)
{
	return (y + win->move_ud);
}
