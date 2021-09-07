# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 15:54:32 by estoffel          #+#    #+#              #
#    Updated: 2021/09/02 19:17:59 by estoffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	\
			ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_itoa.c			\
			ft_itoa_base.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_isspace.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strndup.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_substr.c			\
			ft_strtrim.c		\
			ft_tolower.c		\
			ft_toupper.c		\

BNS		=	\
			ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c		\

OBJ		=	$(SRC:.c=.o)

OBJBNS	=	$(BNS:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJBNS) $(OBJ)
	ar -rcs $(NAME) $(OBJBNS) $(OBJ)
	touch bonus

all:	$(NAME)

clean:
	$(RM) $(OBJ) $(OBJBNS)

fclean:
	$(RM) $(OBJ) $(OBJBNS)
	$(RM) $(NAME) bonus

re:	fclean all

.PHONY: all clean fclean re
