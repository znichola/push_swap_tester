# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 21:29:13 by znichola          #+#    #+#              #
#    Updated: 2022/11/16 23:50:07 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker

FILES	=	execute_ops  input_ops    stack_ops__0 stack_ops__2 utils2 \
			input_num    mian         stack_ops__1 utils
SRC		=	$(addsuffix .c, $(FILES))
OBJ		= 	$(SRC:.c=.o)

PS_SRC	= ../push_swap/
PS_NAME	=	push_swap

INCLUDE	=	checker.h
CC 		=	gcc
# CFLAGS	=	-Wall -Werror -Wextra
CFLAGS	=	-g3
RM		=	rm -f

.c.o :
		$(CC) $(CFLAGS) -I${INCLUDE} -c $< -o $(@)

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE) $(PS_NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)

bonus : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

$(PS_NAME) :
	$(MAKE) -C $(PS_SRC) $(PS_NAME)

re : fclean all

.PHONY : $(NAME) all re clean fclean bonus