# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 17:39:01 by akunegel          #+#    #+#              #
#    Updated: 2023/04/12 18:10:41 by akunegel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

FILES_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:

	${CC} ${CFLAGS} -c ${FILES}
	ar -rsv libft.a ${OBJECTS}

bonus:

	${CC} ${CFLAGS} -c ${FILES_BONUS}
	ar -rsv libft.a ${OBJECTS_BONUS}

clean:

	rm -f *.o

fclean: clean

	rm -f ${NAME}

re:	fclean all
