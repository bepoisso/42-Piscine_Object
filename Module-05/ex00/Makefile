NAME = exec
OBJS_DIR = objs
OUTPUT_DIR = outputs

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS =	main.cpp \
		Simulation.cpp\
		Parsing.cpp\


OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OUTPUT_DIR)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(OUTPUT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
