# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 14:37:38 by gcesar-n          #+#    #+#              #
#    Updated: 2025/02/23 13:16:38 by gcesar-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra

# source files
SRCS = 	src/main.c src/utils.c src/parser.c src/utils_parsing.c \

# object directory
OBJ_DIR = objects

# object files
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/utils.o \
		$(OBJ_DIR)/utils_parsing.o \

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# compilation
$(OBJ_DIR)/main.o: src/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/parser.o: src/parser.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/parser.c -o $(OBJ_DIR)/parser.o

$(OBJ_DIR)/utils_parsing.o: src/utils_parsing.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/utils_parsing.c -o $(OBJ_DIR)/utils_parsing.o
	
$(OBJ_DIR)/utils.o: src/utils.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/utils.c -o $(OBJ_DIR)/utils.o

# object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all