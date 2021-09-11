# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/09/12 00:25:17 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### VARIABLES ######


## CUSTOMIZATION ##

_END		=	\e[0m

_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m

## COMPILATION ##

CC				=	gcc

CC_FLAGS		=	-Wall -Wextra -Werror

## DELETE ##

RM				=	rm -rf

## NORME ##

NORMINETTE		:=	${HOME}/.norminette/norminette.rb

## DIRECTORIES ##

DIR_HEADERS		=	includes/

DIR_SRCS		=	srcs/

DIR_OBJS		=	objs/

SUB_DIRS		=	. \
					char \
					str \
					print \
					mem \
					lst \
					nbr \
					mlx \
					utils

SUB_DIR_OBJS	=	$(SUB_DIRS:%=$(DIR_OBJS)%)

## FILES ##

SRCS			=	char/ft_isalnum.c \
					char/ft_isalpha.c \
					char/ft_isascii.c \
					char/ft_isdigit.c \
					char/ft_isprint.c \
					char/ft_isspace.c \
					char/ft_tolower.c \
					char/ft_toupper.c \
					print/ft_putchar_fd.c \
					print/ft_putxchar_fd.c \
					print/ft_putendl_fd.c \
					print/ft_putnbr_fd.c \
					print/ft_putstr_fd.c \
					print/ft_putbits_fd.c \
					str/ft_split.c \
					str/ft_free_tab.c \
					str/ft_strchr.c \
					str/ft_strdup.c \
					str/ft_strjoin.c \
					str/ft_strlcat.c \
					str/ft_strlcpy.c \
					str/ft_strlen.c \
					str/ft_tablen.c \
					str/ft_strmapi.c \
					str/ft_strncmp.c \
					str/ft_strcmp.c \
					str/ft_strict_strcmp.c \
					str/ft_strnstr.c \
					str/ft_strrchr.c \
					str/ft_strtrim.c \
					str/ft_substr.c \
					str/ft_strrev.c \
					str/ft_strextract.c \
					str/ft_str_end.c \
					str/ft_charset.c \
					str/ft_wdcounter.c \
					nbr/ft_atoi.c \
					nbr/ft_atof.c \
					nbr/ft_itoa.c \
					nbr/ft_nbrlen.c \
					nbr/ft_itox.c \
					nbr/ft_abs.c \
					nbr/ft_max.c \
					nbr/ft_round.c \
					mem/ft_bzero.c \
					mem/ft_calloc.c \
					mem/ft_memalloc.c \
					mem/ft_memchr.c \
					mem/ft_memcmp.c \
					mem/ft_memcpy.c \
					mem/ft_memccpy.c \
					mem/ft_memmove.c \
					mem/ft_memset.c \
					lst/ft_lstadd_back.c \
					lst/ft_lstadd_front.c \
					lst/ft_lstclear.c \
					lst/ft_lstdelone.c \
					lst/ft_lstiter.c \
					lst/ft_lstlast.c \
					lst/ft_lstmap.c \
					lst/ft_lstnew.c \
					lst/ft_lstsize.c \
					utils/get_next_line.c \
					utils/get_next_line_utils.c \
					mlx/ft_color.c

## COMPILED ##

OBJS		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME		=	libft.a

# **************************************************************************** #

###### RULES ######

all:			$(NAME)

## VARIABLES RULES ##

$(NAME):		$(OBJS)
					@printf "\033[2K\r$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
					@ar rcs $(NAME) $(OBJS)
					@ranlib $(NAME)
					@printf "$(_GREEN) Library '$(NAME)' created. $(_END)✅\n"

$(DIR_OBJS)%.o:	$(DIR_SRCS)%.c
					@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
					@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS):	$(SUB_DIR_OBJS)

$(SUB_DIR_OBJS):
					@mkdir -p $(SUB_DIR_OBJS)

## OBLIGATORY PART ##

clean:
					@$(RM) $(DIR_OBJS) test.o log.out test
					@printf "$(_RED) '$(DIR_OBJS)', 'test.o', 'log.out' and 'test' has been deleted. $(_END)🗑️\n"

fclean:			clean
					@$(RM) $(NAME) libft.so
					@printf "$(_RED) '$(NAME)' and 'libft.so' has been deleted. $(_END)🗑️\n"

re:				fclean all

## NORME ##

norme:
					@$(NORMINETTE) $(DIR_SRCS)
					@$(NORMINETTE) $(DIR_HEADERS)

## PHONY ##

.PHONY:			all clean re fclean norme so test

so:				fclean
					@$(CC) -fPIC $(CFLAGS) $(SRC)
					@gcc -shared -o libft.so $(OBJ)

test:			all
					@$(CC) -c test.c -o test.o
					@$(CC) -o test test.o -L. -lft -lm
					@echo "Program output:\n------------------------------------------------"
					@valgrind --leak-check=full -v --track-origins=yes --log-file=log.out ./test | cat -e
					@time -f "------------------------------------------------\nProgram execution time: %es" ./test > /dev/null
					@echo "\nValgrind log file as been created, named log.out"
					@$(RM) test.o
