/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:52:59 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/19 20:22:56 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill_tmp(char **tmp, const int fd)
{
	int		first;
	int		r;
	int		i;
	int		j;
	char			buff[BUFF_SIZE];

	first = 0;
	j = 0;
	i = 0;
	r = 0;
	while (i < BUFF_SIZE)
		buff[i++] = '\0';
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (first++ == 0 && *tmp && ft_strlen(*tmp) != 0)
			ft_strdel(tmp);
		while (r + j <= i)
			buff[r + j++] = '\0';
		if (!(*tmp = ft_strjoinfreefirst(*tmp, buff)))
			return (-1);
		j = 0;
	}
	if (r < 0)
		return (-1);
	return (1);
}


int		get_next_line(const int fd, char **line)
{
	static char		*tmp;
	int				i;

	i = -1;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fill_tmp(&tmp, fd) < 0)
		return (-1);
	*line = ft_strnew(ft_strfind(tmp, '\n') + 1);
	while (++i > -2 && tmp[i] && tmp[i] != '\n')
		(*line)[i] = tmp[i];
	if (!ft_strlen(tmp) && !ft_strlen(*line))
		return (0);
	if (i != (int)ft_strlen(tmp))
		i++;
	ft_strcut(&tmp, i);
	return (1);
}
