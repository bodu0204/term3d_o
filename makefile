# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 01:06:12 by ryoakira          #+#    #+#              #
#    Updated: 2022/02/28 01:57:51 by ryoakira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= term3d
SRC			= change3dto2d.c changevector.c collor.c linear_algebra.c main.c read3d.c readfile.c tool.c stdmov.c
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
