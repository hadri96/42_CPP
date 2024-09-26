NAME= 			span

CC = 			c++

RED =			\033[0;31m
GREEN =			\033[0;32m
BW =			\033[1;37m
YELLOW =		\033[0;33m
BLUE =			\033[0;34m
MAGENTA =		\033[0;35m
CYAN =			\033[0;36m
WHITE =			\033[0;37m
RESET =			\033[0m

CFLAGS = 		-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS = 			main \
				Span

FILES =			$(SRCS:%=%.cpp)

OBJS = 			$(addprefix objs/, $(addsuffix .o, $(SRCS)))

objs/%.o: %.cpp
			@if ! [ -d objs ]; then\
				mkdir objs;\
			fi
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(FILES)
	@echo "$(GREEN) ✅ Compilation done! ✅$(RESET)"
	@echo "$(GREEN) ⚙️ Executable: $(BW)./$(NAME)$(RESET)"

clean:
	@rm -rf objs
	@echo "$(RED) 🗑️ Object files deleted! 🗑️$(RESET)"

fclean:		clean
	@rm $(NAME)
	@if [ -d $(NAME).dSYM ]; then\
		rm -rf $(NAME).d*;\
	fi
	@echo "$(RED) 🗑️ Executable deleted! 🗑️$(RESET)"


re:			fclean all

.PHONY: all clean fclean re
