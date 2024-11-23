CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = main.c parse_init.c philo.c life.c free_whatever.c exxiitt.c
OBJS = $(SRCS:.c=.o)
NAME = philo
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all