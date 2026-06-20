# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 12:43:32 by kjurkows          #+#    #+#              #
#    Updated: 2026/06/20 18:04:22 by kjurkows         ###   ########.fr        #
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

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -lbsd $(GTEST_FLAGS) -o $(BIN_DIR)/$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%:	$(OBJS_DIR)/%.o $(MAIN_OBJ) $(LIBFT) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -L$(LIBFT_DIR) -lft -lbsd $(GTEST_FLAGS) -o $(BIN_DIR)/$@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(BIN_DIR) $(OBJS_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJS_DIR)
	@if [ -d $(LIBFT_DIR) ]; then make -C $(LIBFT_DIR) clean; fi

fclean:	clean
	rm -rf $(BIN_DIR)
	@if [ -d $(LIBFT_DIR) ]; then make -C $(LIBFT_DIR) fclean; fi

re:	fclean all

.PHONY: all clean fclean re
