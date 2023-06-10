NAME = cub3D
SRCS = $(shell find "." -name "*.c")
OBJS = $(SRCS:.c=.o)
INCLUDES = include
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
 