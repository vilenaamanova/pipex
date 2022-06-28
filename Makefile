NAME		=	pipex

NAME_BONUS	=	pipex_bonus

SRC			=	mand/ft_split.c \
				mand/ft_strjoin.c \
				mand/ft_strlen.c \
				mand/ft_strncmp.c \
				mand/errors.c \
				mand/main.c \
				mand/pipex_utils.c \

SRC_BONUS	=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				bonus/errors_bonus.c \
				bonus/ft_split.c \
				bonus/ft_strjoin.c \
				bonus/ft_strlen.c \
				bonus/ft_strncmp.c \
				bonus/limiter_part_bonus.c \
				bonus/main_bonus.c \
				bonus/pipex_utils_bonus.c \

HEADER		=	pipex.h

OBJ			=	$(SRC:c=o)

OBJ_BONUS	=	$(SRC_BONUS:c=o)

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJ) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(NAME_BONUS):	$(OBJ_BONUS) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

%.o:			%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus:			$(NAME_BONUS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)

fclean:			clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re:				fclean all

.PHONY:			clean fclean re
