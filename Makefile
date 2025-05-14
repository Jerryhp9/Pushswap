# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 16:16:30 by jhor              #+#    #+#              #
#    Updated: 2025/05/12 16:16:30 by jhor             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
RM = rm -f

LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = struct.c src/pushswap_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -Ipushswap.h -ILibft/libft.h $(OBJ) $(LIBFT) -o $@

all: $(NAME)


%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	make clean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re