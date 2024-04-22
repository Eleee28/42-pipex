# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:16:19 by elena             #+#    #+#              #
#    Updated: 2024/04/17 16:52:59 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR CODES

DEFAULT = \033[0m

GREEN = \033[92m

RED = \033[91m

YELLOW = \033[93m

BLUE = \033[36m

MAGENTA = \033[95m

CYAN = \033[96m

GRAY = \033[90m

BOLD = \033[1m

# VARIABLES

NAME = pipex

SRC_DIR = srcs

BIN_DIR = bin

LIBFT_DIR = library

CC = cc

CFLAGS += -Wall -Werror -Wextra -g3

REMOVE = rm -f

LIB = ar -crs

INCLUDE = -Ilibrary

# SOURCES

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/pipex_utils.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

all:	$(NAME) msg
		@echo " "

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo " "
	@echo "$(MAGENTA) => MAKE PROGRAM $(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo " "
	@echo "$(CYAN) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME) $(DEFAULT)"
	@echo " "

msg:
	@echo "$(GREEN)==> SO LONG!$(DEFAULT)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "   $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	@echo " "
	@echo "$(MAGENTA) => MAKE LIBS $(DEFAULT)"
	@echo " "
	@echo "$(GREEN)Libft lib...$(DEFAULT)"
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo " "
	@make -sC $(LIBFT_DIR)
	@echo "$(GREEN)Library compiled!$(DEFAULT)"

clean:
	@echo " "
	@echo "$(MAGENTA)=> CLEAN $(DEFAULT)"
	@echo " "
	@make clean -sC $(LIBFT_DIR)
	@echo "$(CYAN)Library object files cleaned$(DEFAULT)"
	@$(REMOVE) $(OBJS)
	@echo "$(CYAN)So long object files cleaned$(DEFAULT)"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "$(CYAN)So long executable files cleaned!$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)Library executable files cleaned!$(DEFAULT)"
	
re: fclean
	@echo " "
	@echo "$(GREEN)Cleaned everything for so long!$(DEFAULT)"
	@$(MAKE) all	

.PHONY: all clean fclean re