# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 13:44:18 by fkathryn          #+#    #+#              #
#    Updated: 2020/09/01 18:44:44 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

SRC = ft_printf.c parse.c types.c write.c \
		decint.c c_char.c percent.c pointer.c  \
		string.c undecint.c unhexint.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
		@cp libft/libft.a $(NAME)
		@ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(LIBFT):
		@$(MAKE) -C ./libft

%.o: %.c ft_printf.h
		@gcc $(CFLAGS) -I ./libft -c $< -o $@ 

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
