NAME=exec
CXX= c++ -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp command.hpp thuesdayDiscount.hpp packageReductionDiscount.hpp

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
