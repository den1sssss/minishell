SRCS		=	splitter.c \
				main.c \
				signals.c \
				parser.c \
				executer.c \
				env.c \
				builtins_f.c \
				builtins_s.c \
				builtins_t.c \
				libft.c \
				ft_split.c

OBJ			=	${SRCS:.c=.o}

CC			=	cc

REMOVE		=	rm -f

CFLAGS		=	-Wall -Werror -Wextra 

NAME		=	minishell

HEADER		=	minishell.h

all:		 $(HEADER) $(NAME)

$(NAME):	$(OBJ) $(HEADER)
			 $(CC) ${OBJ} -o ${NAME} ${CFLAGS} -lreadline
clean:		
			@$(REMOVE) $(OBJ)
fclean:		clean
			@$(REMOVE) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re