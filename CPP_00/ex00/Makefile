NAME= 			megaphone

CC = 			c++

CFLAGS = 		-Wall -Wextra -Werror -std=c++98

SRC = 			megaphone

CPPFILES = 		$(SRC:%=%.cpp)

NAME = 			megaphone

# **************************************************************************** #

all:	$(NAME)

$(NAME):	$(CPPFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(CPPFILES)
	@echo "$(GREEN)✅ Compilation done! ✅$(RESET)"

clean:
	rm -f $(NAME)

.PHONY: all clean
