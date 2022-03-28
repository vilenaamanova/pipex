NAME = pipex

SRC = ft_split.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strncmp.c \
	errors.c \
	main.c \
	pipex_utils.c

HEADER = pipex.h

OBJ = $(SRC:c=o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@rm $(NAME)

re	: fclean all

.PHONY: clean fclean re
