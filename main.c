/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:43:35 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/15 12:15:49 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win	win;

	win.path = argv[1];
	if (argc > 1 && argc < 3)
	{
		default_values(&win);
	}
	else if (argc <= 1)
		ft_putstr("Too few arguments, inser map here !");
	else if (argc >= 3)
		ft_putstr("Too more arguments, inser just one map here !");
	return (0);
}
