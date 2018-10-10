/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:40:51 by maxisimo          #+#    #+#             */
/*   Updated: 2018/04/12 14:28:43 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_color(int p1, int p2, int max)
{
	if (((p1 + p2) / 2) > (max * 0.8))
		return (WHITE);
	else if (((p1 + p2) / 2) == 0)
		return (GREEN3);
	else if (((p1 + p2) / 2) < 0)
		return (BLUE2);
	else
		return (BROWN);
}

int		red_color(int p1, int p2, int max)
{
	if (((p1 + p2) / 2) > (max * 0.8))
		return (YELLOW);
	else if (((p1 + p2) / 2) == 0)
		return (RED1);
	else if (((p1 + p2) / 2) < 0)
		return (RED2);
	else
		return (ORANGE);
}

int		green_color(int p1, int p2, int max)
{
	if (((p1 + p2) / 2) > (max * 0.8))
		return (GREEN1);
	else if (((p1 + p2) / 2) == 0)
		return (GREEN2);
	else if (((p1 + p2) / 2) < 0)
		return (BLUE2);
	else
		return (GREEN3);
}

int		blue_color(int p1, int p2, int max)
{
	if (((p1 + p2) / 2) > (max * 0.8))
		return (BLUE4);
	else if (((p1 + p2) / 2) == 0)
		return (BLUE2);
	else if (((p1 + p2) / 2) < 0)
		return (BLUE3);
	else
		return (BLUE1);
}
