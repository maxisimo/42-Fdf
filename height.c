/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:57:20 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/17 09:51:01 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_height(t_win *win)
{
	win->val_z = (win->val_z + 1.2 <= 0) ? win->val_z : win->val_z + 1.2;
	erase(win);
}

void	decrease_height(t_win *win)
{
	win->val_z = (win->val_z - 1.2 <= 0) ? win->val_z : win->val_z - 1.2;
	erase(win);
}

void	reset(t_win *win)
{
	win->zoom = len_for_zoom(win->path);
	win->val_z = 5;
	win->move_lr = 1;
	win->move_ud = 1;
	win->angle = 0;
	win->ccolor = ORIGIN;
	win->legend_display = ON;
	erase(win);
}

void	free_lst(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
