NAME		= term_3d.out
SRC			= change3dto2d.c changevector.c collor.c linear_algebra.c main.c read3d.c readfile.c tool.c stdmov.c
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./

all : $(NAME) clean

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
