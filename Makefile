SRCS		=	splitter.c \
				main.c \
				signals.c \
				parser.c \
				executer.c

OBJ			=	${SRCS:.c=.o}

CC			=	cc

REMOVE		=	rm -f

CFLAGS		=	-Wall -Werror -Wextra #-lreadline

NAME		=	minishell

LIBFT		=	libft/libft.a

HEADER		=	minishell.h

all:		$(LIBFT) $(HEADER) $(NAME)
$(LIBFT):
			make -C libft/
$(NAME):	$(OBJ) $(HEADER)
			$(CC) ${OBJ} -o ${NAME} ${CFLAGS} ${LIBFT}
			clean
clean:		
			@$(REMOVE) $(OBJ)
			make -C libft/ clean
fclean:		clean
			@$(REMOVE) $(NAME)
			make -C libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re