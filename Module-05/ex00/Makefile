NAME = train_simulation
OBJS_DIR = objs
OUTPUT_DIR = outputs

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRCS =	main.cpp \
		Utils.cpp\
		Simulation.cpp\
		Parsing.cpp\
		Factory.cpp\
		Node.cpp\
		Rail.cpp\
		Train.cpp\
		Movement.cpp\
		Graph.cpp\
		Pathfinder.cpp\
		Time.cpp\
		SimulationEngine.cpp\
		TrainManager.cpp\
		Clock.cpp\
		Event.cpp\
		EventManager.cpp\
		CityDelayedEvent.cpp\
		RailLimitationEvent.cpp\
		RailBlockedEvent.cpp\

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OUTPUT_DIR)

oclean:
	rm -rf $(OUTPUT_DIR)

clean: oclean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all oclean clean fclean re
