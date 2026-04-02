NAME = exec

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	Classroom.cpp \
	Course.cpp \
	CourseFinishedForm.cpp \
	Form.cpp \
	Headmaster.cpp \
	NeedCourseCreationForm.cpp \
	NeedMoreClassRoomForm.cpp \
	Person.cpp \
	Professor.cpp \
	Room.cpp \
	SecretarialOffice.cpp \
	Secretary.cpp \
	Staff.cpp \
	Student.cpp \
	SubscriptionToCourseForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
