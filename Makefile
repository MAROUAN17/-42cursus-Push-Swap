SRCS = sorting_list.c push_swap.c parsing_utils.c push_swap_utils.c push_swap_utils2.c \
	  swap_command.c push_command.c rotate_command.c r_rotate_command.c parsing.c \
	  sort_two_numbers.c sort_three_numbers.c sort_four_numbers.c rest_of_numbers_sort.c \
	  count_cheapest.c count_cheapest_utils.c 
OBJ_FILES = ${SRCS:.c=.o}

SRCS_BNS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./bonus/swap_command_bonus.c ./bonus/rotate_command_bonus.c ./bonus/r_rotate_command_bonus.c ./bonus/push_command_bonus.c \
		./bonus/check_sort_bonus.c ./bonus/checker_bonus.c ./bonus/checker_utils_bonus.c \
	  	./bonus/parsing_bonus.c
OBJ_FILES_BNS = ${SRCS_BNS:.c=.o}

CC = cc
NEXT_LINE_H = ../get_next_line/get_next_line.h
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = libft/libft.a
FT_PRINTF_LIB = ft_printf/libftprintf.a

all: push_swap

${LIBFT_LIB}:
	cd ./libft && make

${FT_PRINTF_LIB}:
	cd ./ft_printf && make

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: ${OBJ_FILES} ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) ${OBJ_FILES} ${LIBFT_LIB} ${FT_PRINTF_LIB} -o push_swap

%_bonus.o: %_bonus.c checker_bonus.h ${NEXT_LINE_H}
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ${OBJ_FILES_BNS} ${LIBFT_LIB} ${FT_PRINTF_LIB}
	$(CC) $(CFLAGS) ${OBJ_FILES_BNS} ${LIBFT_LIB} ${FT_PRINTF_LIB} -o checker

clean:
	rm -f ${OBJ_FILES} ${OBJ_FILES_BNS}
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean: clean
	rm -f push_swap checker
	cd ./libft && make fclean
	cd ./ft_printf && make fclean