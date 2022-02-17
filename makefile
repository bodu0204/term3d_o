NAME		= term_3d.out
SRC			= main.c read3d.c readfile.c tool.c
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

.c.o : $(SRC) $(SRC_b)
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJS_b) $(OBJS)

fclean : clean
	rm -f $(NAME)

push :
	git add .
	git commit -m "push from makefile"
	git push

re : fclean all
