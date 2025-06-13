# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kai-iou <kai-iou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 15:52:52 by amarti            #+#    #+#              #
#    Updated: 2025/06/13 20:02:36 by kai-iou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDES)
RM		=	rm -f
CLONE	=	git clone

libft_url = https://github.com/Kaiiiou/42-libft.git

# === LIBFT ===
libft		= libft
LIBFT	=	$(libft)/libft.a

# === INCLUDES ===
INCLUDES = -I . -I libft

# === SOURCES ===
SRC		=	Pipex.c \
			Pipex_utils.c \
			Pipex_utils1.c \

OBJ		=	$(SRC:.c=.o)

# === RULES ===

all: $(NAME)

$(NAME): $(libft) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(libft):
	$(CLONE) $(libft_url) libft
	$(MAKE) -C $(libft)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(libft) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf $(libft)

re: fclean all

.PHONY: all clean fclean re