# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 20:29:25 by estoffel          #+#    #+#              #
#    Updated: 2021/08/07 20:17:34 by estoffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c	\
			flag_c.c	\
			flag_d.c	\
			flag_i.c	\
			flag_p.c	\
			flag_prct.c	\
			flag_s.c	\
			flag_u.c	\
			flag_x.c	\

#BNS		=	\

OBJ		=	$(addprefix sources/,$(SRC:.c=.o))

#OBJBNS	=	$(BNS:.c=.o)

$(NAME): libft $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft
	#ar -rcs $(NAME) $(OBJ)

libft :
	make -C libft/

bonus: $(OBJBNS) $(OBJ)
	ar -rcs $(NAME) $(OBJBNS) $(OBJ)
	touch bonus

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	# $(OBJBNS)
	make -C libft/ clean

fclean:
	$(RM) $(OBJ) 
	#$(OBJBNS)
	$(RM) $(NAME) bonus a.out
	make -C libft/ fclean

re:	fclean all

.PHONY: all clean fclean re
