/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:42:33 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/17 10:01:45 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_map(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			if (i < win->map_w - 1)
				draw_line(win, &(win->map[j][i]), &(win->map[j][i + 1]));
			if (j < win->map_h - 1)
				draw_line(win, &(win->map[j][i]), &(win->map[j + 1][i]));
			i++;
		}
		j++;
	}
}

void		draw_line(t_win *win, t_point *pt1, t_point *pt2)
{
	int		x[2];
	int		e2;
	t_bres	*bres;

	bres = bres_constr(pt1, pt2, (win->max_z), win);
	x[0] = pt1->d2x;
	x[1] = pt1->d2y;
	while (1)
	{
		if ((check_x(win, x[0]) && check_y(win, x[1])))
			draw_point(win, crt_x(win, x[0]), crt_y(win, x[1]), pt1->color);
		if (x[0] == pt2->d2x && x[1] == pt2->d2y)
			break ;
		if ((e2 = bres->delta_error) > -(bres->delta_x))
		{
			bres->delta_error -= bres->delta_y;
			x[0] += bres->sign_x;
		}
		if (e2 < bres->delta_y)
		{
			bres->delta_error += bres->delta_x;
			x[1] += bres->sign_y;
		}
	}
	free(bres);
}

void		draw_point(t_win *win, int x, int y, int color)
{
	ft_memcpy(&win->data[(x * 4) + (y * win->size)], &(color),
		(size_t)(sizeof(int)));
}

t_bres		*bres_constr(t_point *pt1, t_point *pt2, int max, t_win *win)
{
	t_bres	*bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->delta_x = ft_abs(pt2->d2x - pt1->d2x);
	bres->sign_x = pt1->d2x < pt2->d2x ? 1 : -1;
	bres->delta_y = ft_abs(pt2->d2y - pt1->d2y);
	bres->sign_y = pt1->d2y < pt2->d2y ? 1 : -1;
	bres->delta_error = (bres->delta_x > bres->delta_y ? bres->delta_x :
		-(bres->delta_y)) / 2;
	if (win->ccolor == ORIGIN)
		pt1->color = fdf_color(pt1->d3z, pt2->d3z, max);
	else if (win->ccolor == RED)
		pt1->color = red_color(pt1->d3z, pt2->d3z, max);
	else if (win->ccolor == GREEN)
		pt1->color = green_color(pt1->d3z, pt2->d3z, max);
	else if (win->ccolor == BLUE)
		pt1->color = blue_color(pt1->d3z, pt2->d3z, max);
	return (bres);
}
