NAME        = intern
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
OBJDIR      = obj
SRCS        = main.cpp OldClass/Bureaucrat.cpp OldClass/AForm.cpp \
				OldClass/ShrubberyCreationForm.cpp \
				OldClass/RobotomyRequestForm.cpp \
				OldClass/PresidentialPardonForm.cpp \
				Intern.cpp

OBJS        = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: OldClass/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re