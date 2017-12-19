/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:53:05 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/12/14 17:55:41 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFF_SIZE

# define BUFF_SIZE 32
# include "libft/libft.h"
# include <stdio.h> // DELETE THIS SHIT
# include <stdlib.h>
int		get_next_line(const int fd, char **line);

#endif
