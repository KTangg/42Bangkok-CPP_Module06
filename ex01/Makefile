# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:45:40 by spoolpra          #+#    #+#              #
#    Updated: 2022/05/29 15:38:46 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

TEMPLATE_DIR=/home/samboon/42School/rank04/cpp_modules/classcreate
OBJ_DIR = objs/

NAME = serialization
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJS))
		$(CC) $^ -o $@
$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJ_DIR)
fclean: clean
		$(RM) $(NAME)
re: fclean all

class:
		@$(TEMPLATE_DIR)/createClass.sh $(ARGS)
