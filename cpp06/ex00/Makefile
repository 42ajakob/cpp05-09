NAME	= convert
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp ScalarConverter.cpp
OBJDIR  = obj
OBJS    = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re