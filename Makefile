# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 12:06:19 by sasalama          #+#    #+#              #
#    Updated: 2022/05/17 09:52:09 by salustianos      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strncmp.c path.c \
		pipex.c utils.c

OBJS = ${SRCS:.c=.o}

NAME = pipex

CC = gcc 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
			@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean: 
		${RM} ${OBJS}

fclean: clean 
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

