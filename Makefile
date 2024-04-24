# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:16:19 by elena             #+#    #+#              #
#    Updated: 2024/04/24 10:23:01 by ejuarros         ###   ########.fr        #
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

NAME_BONUS = pipex_bonus

SRC_DIR = srcs

SRC_BONUS_DIR = srcs_bonus

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

SRCS_BONUS =	$(SRC_BONUS_DIR)/main_bonus.c \
				$(SRC_BONUS_DIR)/pipex_bonus.c \
				$(SRC_BONUS_DIR)/pipex_utils_bonus.c \
				$(SRC_BONUS_DIR)/here_doc_bonus.c \
				$(SRC_BONUS_DIR)/childs_bonus.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(BIN_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

all:	$(NAME) msg
		@echo " "

$(NAME): $(OBJS) $(LIBFT)
	@echo " "
	@echo "$(MAGENTA) => MAKE PIPEX $(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo " "
	@echo "$(CYAN) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $(NAME) $(DEFAULT)"
	@echo " "

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@echo " "
	@echo "$(MAGENTA) => MAKE PIPEX BONUS $(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(INCLUDE) -o $(NAME_BONUS)
	@echo " "
	@echo "$(CYAN) $(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(INCLUDE) -o $(NAME_BONUS) $(DEFAULT)"
	@echo " "

msg:
	@echo "$(GREEN)==> PIPEX!$(DEFAULT)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "   $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
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
	@$(REMOVE) $(OBJS) $(OBJS_BONUS)
	@echo "$(CYAN)So long object files cleaned$(DEFAULT)"

fclean: clean
	@$(REMOVE) $(NAME) $(NAME_BONUS)
	@echo "$(CYAN)So long executable files cleaned!$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)Library executable files cleaned!$(DEFAULT)"
	
re: fclean
	@echo " "
	@echo "$(GREEN)Cleaned everything for so long!$(DEFAULT)"
	@$(MAKE) all

bonus: $(NAME_BONUS) msg
	@echo " "	

.PHONY: all clean fclean re