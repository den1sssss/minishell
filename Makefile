# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 14:59:18 by dshirely          #+#    #+#              #
#    Updated: 2022/06/30 14:59:18 by dshirely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	splitter.c \
				main.c \
				signals.c \
				parser.c \
				executer_one.c \
				executer_two.c \
				env_one.c \
				env_two.c \
				builtins_f.c \
				builtins_s.c \
				builtins_t.c \
				libft_one.c \
				libft_two.c \
				ft_split.c \
				redir.c \
				utils.c 

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