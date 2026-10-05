CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

