# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 14:34:20 by bepoisso          #+#    #+#              #
#    Updated: 2026/02/08 14:34:51 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=exec
CXX= c++ -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp # Add other files

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
