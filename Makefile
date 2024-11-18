CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC) #g3 -fsanitize=address

INC = push_swap.h

SRC = push_swap.c push_swap_2.c stack_functions.c ft_split.c push_swap_utils.c stack_functions_2.c rotate.c push_and_rot.c swap.c push_swap_utils_2.c push_swap_utils_3.c butterfly.c butterfly_utils.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = checker.c push_swap_2.c stack_functions.c ft_split.c push_swap_utils.c stack_functions_2.c rotate.c push_and_rot.c swap.c push_swap_utils_2.c push_swap_utils_3.c butterfly.c butterfly_utils.c get_next_line.c get_next_line_utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = push_swap
BONUS = checker

.PHONY = NAME, all, clean, fclean, re, bonus

all: $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ) Makefile push_swap.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS) : $(BONUS_OBJ) Makefile push_swap.h
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $@

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
		rm -f $(NAME)
		rm -f $(BONUS)

re : fclean all