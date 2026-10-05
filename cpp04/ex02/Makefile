NAME = ex02

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
AR = ar rcs
RM = rm -f

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.PHONY: all objects lib clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

objects: $(OBJS)

lib: libex01.a

libex01.a: $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) libex01.a

re: fclean all
