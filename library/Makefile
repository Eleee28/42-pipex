# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 11:34:16 by ejuarros          #+#    #+#              #
#    Updated: 2024/04/22 15:05:17 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR CODES

GREEN = "\033[92m"

RED = "\033[91m"

BLUE = "\033[36m"

CLEAR = "\033[0m"

BOLD = "\033[1m"

#  COMPILATION FLAGS

NAME = libft.a

LIBFT_DIR = libft

PRINTF_DIR = printf

MATRIX_DIR = matrix_utils

GNL_DIR = gnl

SRCS_LIBFT =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
				ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c	 \
				ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c \
				ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c \
				ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c \
				ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c  \
				ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c    \
				ft_strmapi.c	ft_striteri.c								 \
																			 \
				ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c      \
				ft_putnbr_fd.c												 \
																			 \
				ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c	 \
				ft_lstlast.c		ft_lstadd_back.c		ft_lstdelone.c	 \
				ft_lstclear.c		ft_lstiter.c			ft_lstmap.c

SRCS_PRINTF =	ft_flags_bonus.c        ft_putchar_bonus.c      \
				ft_putnbr_bonus.c       ft_putstr_bonus.c       \
				ft_utils_bonus.c		ft_printf_bonus.c       \
				ft_putargs_bonus.c      ft_puthex_bonus.c       \
				ft_putptr_bonus.c       ft_putunsig_bonus.c

SRCS_MATRIX =	ft_add_matrix.c         ft_free_matrix.c		\
				ft_print_matrix.c		ft_len_matrix.c			\
				ft_copy_matrix.c		ft_dup_matrix.c

SRCS_GNL = 		get_next_line_bonus.c 	get_next_line_utils_bonus.c
                                     
MY_SOURCES = 	$(SRCS_LIBFT:%.c=$(LIBFT_DIR)/%.c) 		\
				$(SRCS_PRINTF:%.c=$(PRINTF_DIR)/%.c) 	\
				$(SRCS_MATRIX:%.c=$(MATRIX_DIR)/%.c)	\
				$(SRCS_GNL:%.c=$(GNL_DIR)/%.c)

MY_OBJECTS = $(MY_SOURCES:.c=.o)

REMOVE = rm -f

LIB = ar -crs

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)
#	@echo $(BLUE) $(BOLD)"Library built successfully\n"$(CLEAR)

$(NAME): $(MY_OBJECTS)
#	@echo $(GREEN)"> Compiling library\n"$(CLEAR)
	@$(LIB) $(NAME) $(MY_OBJECTS)

clean:
#	@echo $(RED)"> Removing library object files...\n"$(CLEAR)
	@$(REMOVE) $(MY_OBJECTS)

fclean: clean
#	@echo $(RED)"> Removing library...\n"$(CLEAR)
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
# .PHONY used to mark a target as phony: it doesn't consider for execution any file that matches its name.


