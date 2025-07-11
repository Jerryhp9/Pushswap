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
CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address -g
NAME = push_swap
RM = rm -f

LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = parsing/struct.c hfunction/pushswap_utils.c operations/swap_a.c \
operations/rotate_a.c operations/r_rotate_a.c operations/push_b.c \
operations/swap_b.c operations/rotate_b.c operations/r_rotate_b.c \
operations/push_a.c operations/swap_s.c operations/r_rotate_r.c \
operations/rotate_r.c quick_sort/sort3.c quick_sort/sort5.c \
quick_sort/bubble_sort_chunk.c quick_sort/split3.c \
quick_sort/mailman.c quick_sort/quick_sort.c quick_sort/sort_top3.c \
quick_sort/chunk_data_presort.c quick_sort/sort2.c parsing/error.c \
parsing/parse.c

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