NAME = getnextline.a

SRCS =  get_next_line.c \
		get_next_line_utils.c \
		

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

.SECONDARY : $(OBJ)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
