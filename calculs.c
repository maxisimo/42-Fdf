/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:34:00 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/03 10:51:04 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcule_coord(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			calculate(win, &(win->map[j][i]));
			i++;
		}
		j++;
	}
	draw_map(win);
}

void		rotate_x(t_win *win, t_rp *rp)
{
	rp->px = rp->x;
	rp->py = rp->y * cos(win->angle) - rp->z * sin(win->angle);
	rp->pz = rp->y * sin(win->angle) + rp->z * cos(win->angle);
}

void		rotate_y(t_win *win, t_rp *rp)
{
	rp->px = rp->x * cos(win->angle) + rp->z * sin(win->angle);
	rp->py = rp->y;
	rp->pz = rp->x * -sin(win->angle) + rp->z * cos(win->angle);
}

void		rotate_z(t_win *win, t_rp *rp)
{
	rp->px = rp->x * cos(win->angle) - rp->y * sin(win->angle);
	rp->py = rp->x * sin(win->angle) + rp->y * cos(win->angle);
	rp->pz = rp->z;
}

void		calculate(t_win *win, t_point *pt)
{
	t_rp	*rp;

	rp = (t_rp *)malloc(sizeof(t_rp));
	rp->x = pt->d3x * win->zoom;
	rp->y = pt->d3y * win->zoom;
	rp->z = pt->d3z * win->val_z;
	if (win->rot == ROT_Z)
		rotate_z(win, rp);
	else if (win->rot == ROT_Y)
		rotate_y(win, rp);
	else
		rotate_x(win, rp);
	pt->d2x = rp->px - rp->py + WIN_W * 0.5;
	pt->d2y = -rp->pz + rp->px * 0.5 + rp->py * 0.5 + WIN_H * 0.3;
	free(rp);
}
