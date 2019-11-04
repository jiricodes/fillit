# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 10:28:32 by jnovotny          #+#    #+#              #
#    Updated: 2019/11/04 13:05:22 by asolopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  test
GEN = tetrogen
LIB = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra
FTS =	initialize_map.c \
		bit_fts_basic.c \
		score_rules.c \
		print_map.c \
		copy_tetrimino.c \
		solve.c \
		tetr_to_map.c \
		compare_map.c \
		get_input.c \
		store_input.c \
		test_bit.c
GFT = tetrimino_generator.c
TFILE =	testext1 \
		testext2 \
		testext3
OUT = _userout

.PHONY: all clean fclean re run1 run2 runa

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(LIB) $(FTS)

clean:
	@/bin/rm -f *$(OUT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

gentor:
	@/bin/rm -f tetrimino_testfile_*
	gcc -o $(GEN) $(LIB) $(GFT)

# run1: clean
# 	@./test 1 $(TFILE)

# run2:
# 	@/bin/rm -f merge_userout
# 	@./test 2 $(TFILE)
	
# runa: run1 run2
# 	@./compare.sh