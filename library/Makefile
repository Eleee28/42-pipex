# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 11:34:16 by ejuarros          #+#    #+#              #
#    Updated: 2024/07/02 22:24:50 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################### COLORS ####################################
DEFAULT	= \033[0m
GREEN	= \033[92m
YELLOW	= \033[93m
MAGENTA	= \033[95m
CYAN	= \033[96m
################################## VARIABLES ###################################

# Library name
NAME		= libft.a

# Libft directory
LIBFT_DIR	= libft

# Printf directory
PRINTF_DIR	= printf

# Matrix directory
MATRIX_DIR	= matrix_utils

# Gnl directory
GNL_DIR		= gnl

# Objects directory
BIN_DIR		= bin

################################################################################

# Compilation & linker variables
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
LIB = ar -crs

# Remove flags
REMOVE 	:= rm -f

################################################################################

# Possible source files path
VPATH = gnl:libft:printf:matrix_utils

# Libft source files
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

# Printf source files
SRCS_PRINTF =	ft_flags_bonus.c        ft_putchar_bonus.c      \
				ft_putnbr_bonus.c       ft_putstr_bonus.c       \
				ft_utils_bonus.c		ft_printf_bonus.c       \
				ft_putargs_bonus.c      ft_puthex_bonus.c       \
				ft_putptr_bonus.c       ft_putunsig_bonus.c

# Matrix source files
SRCS_MATRIX =	ft_add_matrix.c		ft_free_matrix.c	ft_len_matrix.c		\
				ft_copy_matrix.c	ft_dup_matrix.c		ft_print_matrix.c

# Gnl source files
SRCS_GNL = 		get_next_line_bonus.c 	get_next_line_utils_bonus.c

# Object files
MY_OBJECTS = 	$(SRCS_LIBFT:%.c=$(BIN_DIR)/%.o)  \
				$(SRCS_PRINTF:%.c=$(BIN_DIR)/%.o) \
				$(SRCS_MATRIX:%.c=$(BIN_DIR)/%.o) \
				$(SRCS_GNL:%.c=$(BIN_DIR)/%.o)

################################################################################

# Main rule
all: 	$(NAME) msg

# Library compilation
$(NAME): $(MY_OBJECTS)
	@echo
	@echo
	@$(LIB) $(NAME) $(MY_OBJECTS)

# Objects compilation
$(BIN_DIR)/%.o: %.c
	@mkdir -p $(BIN_DIR)
	@echo -n "\033[2K\r🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

################################################################################

clean:
	@$(REMOVE) $(MY_OBJECTS)
	@echo "$(CYAN)Library object files cleaned$(DEFAULT)"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "$(CYAN)Library executable files cleaned!$(DEFAULT)"
	@echo

re: fclean all

################################################################################

msg:
	@echo "$(GREEN)✨ LIB!$(DEFAULT)"
	@echo

################################################################################
.PHONY: all clean fclean re 
# .PHONY used to mark a target as phony: it doesn't consider for execution
# any file that matches its name.