# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:23:59 by abonnefo          #+#    #+#              #
#    Updated: 2023/03/10 11:15:43 by abonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS = srcs/push_swap.c \
	srcs/push.c \
	srcs/reverse_rotate.c \
	srcs/rotate.c \
	srcs/sort_big_pile.c \
	srcs/sort_medium_pile.c \
	srcs/sort_small_pile.c \
	srcs/swap.c \
	srcs/utils_at.c \
	srcs/utils_free.c \
	srcs/utils_set.c \
	srcs/utils_sort_find.c \
	srcs/utils_sort_move.c \
	srcs/utils_sort_pos.c \
	srcs/utils_sort.c \
	srcs/verif_arg.c \

SRC_LIBFT = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \

SRC_LIBFT_BONUS = libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstclear.c \
	libft/ft_lstdelone.c \
	libft/ft_lstiter.c \
	libft/ft_lstlast.c \
	libft/ft_lstmap.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c \

SRCS_GNL = libft/GNL/get_next_line.c \
	libft/GNL/get_next_line_utils.c \

SRCS_PRINTF = libft/ft_printf/ft_printf.c \
	libft/ft_printf/ft_print_%.c \
	libft/ft_printf/ft_print_c.c \
	libft/ft_printf/ft_print_d.c \
	libft/ft_printf/ft_print_p.c \
	libft/ft_printf/ft_print_s.c \
	libft/ft_printf/ft_print_u.c \
	libft/ft_printf/ft_print_x.c \

OBJS = $(SRCS:.c=.o) $(SRC_LIBFT:.c=.o) $(SRC_LIBFT_BONUS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_PRINTF:.c=.o)

AR = ar rcs

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[5;36m\n-gcc *.c libft done\033[0m"
	@echo "\033[5;36m-gcc *.c get_next_line done\033[0m"
	@echo "\033[5;36m-gcc *.c ft_printf done\033[0m"
	@echo "\033[5;36m-gcc *.c push_swap done\n\033[0m"
	@echo "\033[1;32m[Make : 'push_swap' is done]\033[0m"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "\033[1;33m[.o] Object files removed\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[1;33m[.a] Binary file removed\033[0m"

re : fclean all

.PHONY: all clean fclean re
