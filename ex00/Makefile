# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 09:27:36 by bepoisso          #+#    #+#              #
#    Updated: 2026/01/26 12:10:31 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=exec
CXX= c++  -std=c++98 -g #-Wall -Wextra -Werror

SRCS = main.cpp Account.cpp Bank.cpp

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
