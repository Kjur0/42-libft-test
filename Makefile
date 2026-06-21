# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 12:43:32 by kjurkows          #+#    #+#              #
#    Updated: 2026/06/21 10:34:53 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft-test

CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17

LIBFT_DIR	=	./libft
SRCS_DIR	=	./srcs
BIN_DIR		=	./bin
OBJS_DIR	=	./build

LIBFT		=	$(LIBFT_DIR)/libft.a
GTEST_FLAGS	=	-lgtest -lpthread
INCLUDES	=	-I$(LIBFT_DIR)

SRCS		=	$(wildcard $(SRCS_DIR)/*.cpp)
OBJS		=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))
MAIN_OBJ	=	$(OBJS_DIR)/_main.o

RM			=	rm -f

RED			=	\033[;31m
GREEN		=	\033[;32m
YELLOW		=	\033[;33m
BLUE		=	\033[;34m
MAGENTA		=	\033[;35m
CYAN		=	\033[;36m
RESET		=	\033[0m
POSITION	=	\033[2K\r

all:	$(NAME)
	@echo "$(GREEN)$(NAME) is ready to use.$(RESET)"

$(NAME):	$(LIBFT) $(OBJS) | $(BIN_DIR)
	@echo "$(BLUE)Creating $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -lbsd $(GTEST_FLAGS) -o $(BIN_DIR)/$(NAME)
	@echo "$(GREEN)$(NAME) has been created successfully!$(RESET)"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	@echo -n "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(POSITION)$(GREEN)Compiled $< successfully!$(RESET)"

%:	$(OBJS_DIR)/%.o $(MAIN_OBJ) $(LIBFT) | $(BIN_DIR)
	@echo "$(BLUE)Creating $@...$(RESET)"
	@$(CXX) $(CXXFLAGS) $^ -L$(LIBFT_DIR) -lft -lbsd $(GTEST_FLAGS) -o $(BIN_DIR)/$@
	@echo "$(GREEN)$@ has been created successfully!$(RESET)"

$(LIBFT):
	@if [ ! -d $(LIBFT_DIR) ]; then echo "$(RED)Error: libft directory not found!$(RESET)"; exit 1; fi
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)libft has been built successfully!$(RESET)"

$(BIN_DIR) $(OBJS_DIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJS_DIR)
	@if [ -d $(LIBFT_DIR) ]; then make -C $(LIBFT_DIR) clean; fi
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean:	clean
	@$(RM) $(BIN_DIR)
	@if [ -d $(LIBFT_DIR) ]; then make -C $(LIBFT_DIR) fclean; fi
	@echo "$(RED)Fully cleaned all generated files.$(RESET)"

re:	fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re
