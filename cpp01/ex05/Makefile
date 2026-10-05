CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex05


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re