NAME=exec
CXX= c++ -Wall -Wextra -Werror

LOG_FILES =	log_const_header.txt\
			log_date_header.txt\
			log_no_header.txt

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(LOG_FILES)

re : fclean all

.PHONY : all clean fclean re
