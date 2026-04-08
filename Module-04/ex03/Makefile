NAME=exec
CXX= c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Form.cpp Headmaster.cpp CourseFinishedForm.cpp NeedCourseCreationForm.cpp NeedMoreClassRoomForm.cpp Secretary.cpp SubscriptionToCourseForm.cpp Person.cpp Staff.cpp Room.cpp Professor.cpp Student.cpp Course.cpp Classroom.cpp

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
