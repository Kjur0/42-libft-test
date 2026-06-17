# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 10:41:30 by kjurkows          #+#    #+#              #
#    Updated: 2026/06/17 15:35:54 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Ilibft -g
LDFLAGS		=	-Llibft -lft

SRCDIR		=	./srcs
OUTDIR		=	./bin

 # all .c file basename in srcs
TESTS		=	$(patsubst $(SRCDIR)/%.c, %, $(wildcard $(SRCDIR)/*.c))

RM			=	rm -rf

all: libft $(TESTS)

%: $(SRCDIR)/%.c
	@mkdir -p $(OUTDIR)
	@$(CC) $(CFLAGS) -o $(OUTDIR)/$@ $< $(LDFLAGS)

pre:
	@make -C libft

debug: CFLAGS += -g
debug: all

clean:
	@$(RM) $(OUTDIR)
	@make -C libft clean

.PHONY: pre debug clean
