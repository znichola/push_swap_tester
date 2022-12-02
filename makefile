# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 21:29:13 by znichola          #+#    #+#              #
#    Updated: 2022/11/17 17:11:25 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker

FILES	=	execute_ops  input_ops    stack_ops__0 stack_ops__2 utils2 \
			input_num    mian         stack_ops__1 utils
SRC		=	$(addsuffix .c, $(FILES))
OBJ		= 	$(SRC:.c=.o)

PS_SRC	=	../push_swap/
PS_NAME	=	push_swap
PUSH	=	$(PS_SRC)$(push_swap)

INCLUDE	=	checker.h \
			libft/libft.h \
			libft/printf/ft_printf.h \
			libft/get_next_line/get_next_line.h
INC_PAR	=	$(addprefix -I, $(INCLUDE))


CC 		=	gcc
# CFLAGS	=	-Wall -Werror -Wextra
CFLAGS	=	-g
RM		=	rm -f

# submodule
# libft
LIB_DIR	=	libft
LIB_N	=	libft.a
LIB		=	$(LIB_DIR)/$(LIB_N)

.c.o :
		$(CC) $(CFLAGS) $(INC_PAR) -c $< -o $(@)

all : $(NAME)

$(NAME) : $(LIB) $(PUSH) $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC_PAR) -L$(LIB_DIR) -lft

bonus : $(NAME)

clean :
	$(RM) $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

# push_swap program
$(PUSH) :
	$(MAKE) -C $(PS_SRC) $(PS_NAME)

re : fclean all

# libft
$(LIB):
		$(MAKE) -C $(LIB_DIR) $(LIB_N)
		cp $(LIB) $(NAME)

.PHONY : $(NAME) all re clean fclean bonus

# .SILENT: