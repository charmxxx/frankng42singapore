TARGET = ft_tail
SRCFILE = main.c
SRCPATH = ./src/
SRCS = $(addprefix $(SRCFILE), $(SRCPATH))
OBJS = $(SRCS:.c=.o)
HEADERS = ./include/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)
RM = rm -f

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

