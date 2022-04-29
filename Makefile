# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 19:24:43 by dshirely          #+#    #+#              #
#    Updated: 2022/04/29 19:28:11 by dshirely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		=	*.c
				
OBJS		= ${SRCS:.c=.o}

CC			= cc
AR			= ar rcs
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
HEADER		= minishell.h

all:	${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} $?

${OBJS} : ${HEADER} Makefile

.c.o:	
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:	
		${RM} ${OBJS}
		
fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re

save :
	@printf "\033[36;1m@@@ auto saving minishell ...\033[0m\n"
	@git commit -m 29/4
	@git push