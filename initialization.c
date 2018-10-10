/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:13:42 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/15 12:13:59 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_values(t_win *win)
{
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, WIN_W, WIN_H, "FdF");
	win->zoom = len_for_zoom(win->path);
	win->val_z = 5;
	win->move_lr = 0;
	win->move_ud = 0;
	win->angle = 0;
	win->rot = ROT_Z;
	win->ccolor = 0;
	win->legend_display = ON;
	win->img = mlx_new_image(win->init, WIN_W, WIN_H);
	win->data = mlx_get_data_addr(win->img, &(win->color), &(win->size),
		&(win->endian));
	win->map = create_map(win);
	mlx_hook(win->win, 2, (1L << 0), &key_hook, win);
	mlx_expose_hook(win->win, expose_hook, win);
	mlx_loop(win->init);
}
