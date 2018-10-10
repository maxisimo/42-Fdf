/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:32:56 by maxisimo          #+#    #+#             */
/*   Updated: 2018/05/17 09:50:52 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		len_tab(char *argv)
{
	int		fd;
	char	*buff;
	int		ret;
	int		size;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Fdf");
		exit(1);
	}
	buff = (char *)ft_strnew(200);
	size = 0;
	while ((ret = read(fd, buff, 200)) > 0)
	{
		if (ret == -1)
		{
			perror("Fdf");
			exit(1);
		}
		size += ret;
	}
	close(fd);
	free(buff);
	return (size);
}

int		count_map_length(char **str)
{
	int		count;

	count = 0;
	while (str[count] != NULL)
		count++;
	return (count);
}

void	erase(t_win *win)
{
	ft_bzero(win->data, WIN_H * WIN_W * 4);
	expose_hook(win);
}

int		ft_abs(int nb)
{
	nb < 0 ? nb *= -1 : (0);
	return (nb);
}

int		len_for_zoom(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (i <= 20)
		return (35);
	return (10);
}
