NAME = exec

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
	School.cpp\
	Form.cpp \
	Headmaster.cpp \
	CourseFinishedForm.cpp \
	NeedCourseCreationForm.cpp \
	NeedMoreClassRoomForm.cpp \
	Secretary.cpp \
	SubscriptionToCourseForm.cpp \
	Classroom.cpp \
	Course.cpp \
	Person.cpp \
	Professor.cpp \
	Room.cpp \
	Student.cpp \
	SecretarialOffice.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
