# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 20:29:25 by estoffel          #+#    #+#              #
#    Updated: 2021/09/08 23:46:16 by estoffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	check_conv.c\
			conv_c.c	\
			conv_id.c	\
			conv_p.c	\
			conv_s.c	\
			conv_u.c	\
			conv_x.c	\
			ft_printf.c	\

OBJ		=	$(addprefix sources/,$(SRC:.c=.o))

$(NAME): $(OBJ)
	make -C includes/libft/
	cp includes/libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJBNS) $(OBJ)
	ar -rcs $(NAME) $(OBJBNS) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	make -C includes/libft/ clean

fclean:
	$(RM) $(OBJ) 
	$(RM) $(NAME) a.out
	make -C includes/libft/ fclean

re:	fclean all

.PHONY: all clean fclean re
