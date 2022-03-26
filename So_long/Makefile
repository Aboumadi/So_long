NAME = so_long

HEADER = so_long.h

SRC = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\
	src/ft_strlen2.c src/ft_strcmp.c src/ft_checking_map.c src/ft_strncmp.c src/ft_parsing.c\
	src/ft_substr.c src/ft_error.c src/ft_mouvment.c src/destroy_window.c src/read_map.c\
	printf/ft_printf.c printf/ft_putnbr_base10_ns2.c printf/ft_putnbr_base10.c\
	printf/ft_putchar.c\
	so_long.c
	
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

FRAME = -lmlx -framework OpenGL -framework AppKit

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(FRAME) $(OBJ) -o $(NAME)

clean : 
	@rm -f $(OBJ)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all