# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 20:57:42 by spoliart          #+#    #+#              #
#    Updated: 2021/09/11 23:28:06 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m

_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m

S = srcs/
O = objs/
I = includes/

FDF = fdf

SRCS =	main.c \
		fdf.c \
		parsing.c \
		param.c \
		color.c \
		hook.c \
		error.c
OBJS = $(SRCS:%.c=$O%.o)

CC = gcc
CFLAGS += -O3 -Wall -Wextra -Werror
LDFLAGS += -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
INC = -I$I -Imlx_linux

RM = /bin/rm

all:	$(FDF)

$(FDF):	$(OBJS)
	@printf "\033[2K\r$(_GREEN) All $@ files compiled into '$O'. $(_END)✅\n"
	@make -C libft/ all
	@make -C mlx_linux/ all
	@$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)
	@printf "$(_GREEN) Binary '$(FDF)' created. $(_END)✅\n"

$O:
	@mkdir -p $@

$(OBJS): | $O

$O%.o: $S%.c
	@printf "\033[2K\r$(_YELLOW)Compiling $< $(_END)⌛"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C libft/ clean
	@make -C mlx_linux/ clean
	@$(RM) -rf $O
	@printf "$(_RED) '$O' has been deleted. $(_END)🗑️\n"

fclean: clean
	@make -C libft/ fclean
	@$(RM) -f $(FDF)
	@printf "$(_RED) '$(FDF)' has been deleted. $(_END)🗑️\n"

re: fclean all

push: fclean
	@git add .
	@git commit -m "fdf"
	@git push

.PHONY:	all FDF clean fclean re
