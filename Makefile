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
CFLAGS = -g -Wall -Werror -Wextra
NAME = push_swap
RM = rm -f

LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = struct.c hfunction/pushswap_utils.c operations/swap_a.c \
operations/rotate_a.c operations/r_rotate_a.c operations/push_b.c \
operations/swap_b.c operations/rotate_b.c operations/r_rotate_b.c \
operations/push_a.c operations/swap_s.c operations/r_rotate_r.c \

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