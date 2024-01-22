SRCS = sorting_list.c push_swap.c push_swap_utils.c swap_command.c push_command.c rotate_command.c r_rotate_command.c parsing.c
OBJ_FILES = ${SRCS:.c=.o}

CC = cc
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
	$(CC) $(CFLAGS) -fsanitize=address -g ${OBJ_FILES} ${LIBFT_LIB} ${FT_PRINTF_LIB} -o push_swap

clean:
	rm -f ${OBJ_FILES}
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean: clean
	rm -f push_swap
	cd ./libft && make fclean
	cd ./ft_printf && make fclean