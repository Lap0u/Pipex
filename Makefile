# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 01:49:38 by cbeaurai          #+#    #+#              #
#    Updated: 2021/09/28 12:37:25 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex

SRC  	= parse/args.c error/error.c solve/pipex.c solve/utils.c parse/utils.c
		  
OBJS 	= $(SRC:.c=.o)

CC 	 	= clang

CFLAGS 	= -Wall -Werror -Wextra

ARRCS	= ar rcs

LFT		= ./global

LIB	=  -L. -l_pipex -L ./global -lft 

RM		= rm -rf

all		: $(LFT) $(OBJS) ${NAME}

.c .o	:
			${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

MAKE_LIB= ${MAKE} -C ${LFT}

${NAME}	:	${OBJS}
			${MAKE_LIB}	
			${ARRCS} lib_pipex.a ${OBJS}
			${CC} ${CFLAGS} main.c -o ${NAME} ${LIB}

clean	:
			${RM} ${OBJS} lib_pipex.a
			${MAKE_LIB} clean

fclean	:	clean
			${RM} ${NAME} pipex.dSYM
			${MAKE_LIB} fclean

re		:	fclean all
