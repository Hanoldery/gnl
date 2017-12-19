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

int		get_next_line(const int fd, char **line)
{
	static char		*tmp;
	char			buff[BUFF_SIZE];
	int				r;
	int				i;
	int				j;

	i = 0;
	j = 0;
	r = 0;
	while (i < BUFF_SIZE)
		buff[i++] = '\0';
	printf("\t0.1 _%s_\n", buff);
	printf("\t0.2 _%s_\n", tmp);
	//printf("\n-----------\n0.0\n");
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while (((r = read(fd, buff, BUFF_SIZE)) > 0))
	{
		while (r + j < i)
			buff[r + j++] = '\0';
		buff[i] = '\0';
		printf("\t1.1 _%s_r%d i%d b%d\n", buff, r, i, (int)ft_strlen(buff));
		if (!(tmp = ft_strjoinfreefirst(tmp, buff)))
			return (-1);
		j = 0;
		//printf("\t0.1 _%s_\n", buff);
	}
	i = 0;
	if (r < 0)
		return (-1);
	//printf("2.0\n");
	*line = ft_strnew(ft_strfind(tmp, '\n') + 1);
	printf("3.0 %d_%s_\n", ft_strfind(tmp, '\n'), *line);
	while (tmp[i] && tmp[i] != '\n')
	{
		(*line)[i] = tmp[i];
		i++;
	}
	printf("\t\t4.0 _%s_\n", *line);
	if (i == ft_strlen(tmp))
		ft_strcut(&tmp, i);
	else
		ft_strcut(&tmp, i + 1);
	if (!ft_strlen(tmp))
	{
		while (ft_strlen(tmp) > 0)
			tmp[ft_strlen(tmp)] = '\0';
		printf("\t\t5.0 _%s_\n", tmp);
		//free(tmp);
		return (0);
	}
	//printf("5.0\n");
	return (1);
}
