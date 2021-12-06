NAME		=	day6_puzzle2
SRCDIR		=	srcs
SRCS		=	main.cpp
OBJDIR		=	objs
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
CC			=	clang++
FLAGS		=	
INCS		=	includes/

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	@echo "You can now run ./$(NAME), enjoy!"

$(OBJDIR)/%.o:  $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INCS)

clean:
	@rm -rf $(OBJDIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re .cpp.o
