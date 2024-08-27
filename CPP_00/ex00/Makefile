NAME= 			megaphone

CC = 			c++

CFLAGS = 		-Wall -Wextra -Werror -std=c++98

SRC = 			megaphone

RED =			\033[0;31m
GREEN =			\033[0;32m
YELLOW =		\033[0;33m
BLUE =			\033[0;34m
MAGENTA =		\033[0;35m
CYAN =			\033[0;36m
WHITE =			\033[0;37m
BW =			\033[1;37m
RESET =			\033[0m

CPPFILES = 		$(SRC:%=%.cpp)

NAME = 			megaphone

# **************************************************************************** #

all:	$(NAME)

$(NAME):	$(CPPFILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(CPPFILES)
	@echo "$(GREEN)✅ Compilation done! ✅$(RESET)"
	@echo "$(GREEN) ⚙️ Executable: $(BW)./$(NAME)$(RESET)"

clean:
	@rm -f $(NAME)

re:		clean all

.PHONY: all clean re
