/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:53:03 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/19 16:36:36 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdlib.h"
#include "stdio.h"
#include <fcntl.h>


int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	argc = 0;
	argv = 0;
	line = (char *)malloc(sizeof(line) * 200);

	printf("0'%s'%p'\n", line, line);
	fd = open("testfile.txt", O_RDONLY);
	printf("%d\n", fd);
	printf("return %d\n", get_next_line(fd, &line));
	printf("_%s_\n", line);
	printf("return %d\n", get_next_line(fd, &line));
	printf("_%s_\n", line);
	printf("return %d\n", get_next_line(fd, &line));
	printf("_%s_\n", line);
	printf("return %d\n", get_next_line(fd, &line));
	printf("_%s_\n", line);
	printf("return %d\n", get_next_line(fd, &line));
	printf("_%s_\n", line);
	printf("return %d\n", get_next_line(fd, &line));
	printf("_%s_\n", line);
}
