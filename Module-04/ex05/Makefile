NAME = exec
OBJS_DIR = objs

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

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
