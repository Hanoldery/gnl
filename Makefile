# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/11 13:08:28 by pgerbaud          #+#    #+#              #
#    Updated: 2017/12/19 15:19:10 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.out

INCLUDE_PATH = get_next_line.h libft/

SRCS = 	get_next_line.c \
		main.c

LIBFT_SRC = putchar \
			putstr \
			putchar_fd \
			putstr_fd \
			strmchr \
			strmintchr \
			atoi \
			itoa \
			iprintsize \
			uiprintsize \
			strchr \
			strsub \
			bzero \
			lstnew \
			lstadd \
			memcpy \
			memalloc \
			strlen \
			strfind \
			strdel \
			strdup \
			strcpy \
			strcut \
			strncpy \
			strncmp \
			strfill \
			strcat \
			strncat \
			strnew \
			imaxtoa \
			uimaxtoa \
			strjoinfree \
			strjoinfreefirst \
			imaxtoa_base \
			uimaxtoa_base \
			strdelinside
#CFLAGS += -Wall -Wextra -Werror

CFLAGS += $(foreach d, $(INCLUDE_PATH), -I$d)

OBJS = $(patsubst %.c,%.o, $(SRCS))

OBJS += $(foreach ft, $(LIBFT_SRC),libft/ft_$(ft).o)


all : $(NAME)

re : fclean all

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

libft/%.o : libft/%.c
	gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) main.o
	gcc -o main.out $(OBJS)

clean :
	rm -rf $(OBJS) main.o

main : $(OBJS) main.o
	gcc -o main.out $(OBJS)

fclean : clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
