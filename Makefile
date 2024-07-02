# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:16:19 by elena             #+#    #+#              #
#    Updated: 2024/07/02 22:31:06 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################### COLORS ####################################
DEFAULT	= \033[0m
GREEN	= \033[92m
YELLOW	= \033[93m
MAGENTA	= \033[95m
CYAN	= \033[96m
################################## VARIABLES ###################################

# Mandatory executable
NAME 		= pipex

# Bonus executable
NAME_BONUS 	= pipex_bonus

# Library directory
LIB_DIR		= library

# Objects directory
BIN_DIR 	= bin

# Temporary file for traking compilation
TMP			= $(BIN_DIR)/.tmp

################################################################################

# Compilation variables
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra

# Remove flags
REMOVE	:= rm -rf

# Make flags
MAKEFLAGS	+= -s

INCLUDE 	= -Ilibrary

################################################################################

# Possible source files path
VPATH = srcs:srcs_bonus

# Library file
LIB = $(LIB_DIR)/libft.a

# Source files
SRCS =	main.c \
		pipex.c \
		pipex_utils.c \

SRCS_BONUS =	main_bonus.c \
				pipex_bonus.c \
				pipex_utils_bonus.c \
				here_doc_bonus.c \
				childs_bonus.c

# Object files
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(BIN_DIR)/%.o)

################################################################################

# Main rule
all:	$(NAME) msg
		@echo

# Pipex compilation
$(NAME): $(LIB) $(OBJS)
	@rm -rf $(TMP)
	@echo
	@$(CC) $(OBJS) $(LIB) $(INCLUDE) -o $(NAME)

# Objects compilation
$(BIN_DIR)/%.o: %.c
	@mkdir -p $(BIN_DIR)
	@if [ ! -e $(TMP) ]; then \
		touch $(TMP); \
		echo "$(MAGENTA)🔶 MAKE PROGRAM 🔶$(DEFAULT)\n"; \
	fi
	@echo -n "\033[2K\r🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Library compilation
$(LIB): 
	@echo
	@echo "$(MAGENTA)🔶 MAKE LIBS 🔶$(DEFAULT)"
	@echo
	@make -C $(LIB_DIR)

################################################################################

bonus: $(NAME_BONUS) msg_bonus
	@echo

$(NAME_BONUS): $(LIB) $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIB) $(INCLUDE) -o $(NAME_BONUS)
	@echo

################################################################################

aux_clean:
	@$(REMOVE) $(OBJS) $(OBJS_BONUS) $(BIN_DIR)
	@echo "$(CYAN)Pipex object files cleaned$(DEFAULT)"

clean: msg_clean
	@make clean -C $(LIB_DIR)
	@make aux_clean
	@echo

fclean: msg_clean aux_clean
	@$(REMOVE) $(NAME) $(NAME_BONUS)
	@echo "$(CYAN)Pipex executable files cleaned!$(DEFAULT)"
	@echo
	@make fclean -C $(LIB_DIR)

re: fclean
	@echo "$(GREEN)Cleaned everything for pipex!$(DEFAULT)"
	@make all

################################################################################

msg:
	@echo
	@echo "$(GREEN)✨ PIPEX!$(DEFAULT)"

msg_bonus:
	@echo
	@echo "$(GREEN)✨ PIPEX BONUS!$(DEFAULT)"

msg_clean:
	@echo
	@echo "$(MAGENTA)🔶 CLEAN 🔶$(DEFAULT)"
	@echo

################################################################################
.PHONY: all bonus aux_clean clean fclean re msg msg_bonus msg_clean