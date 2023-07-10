TARGET := ft_cat
SRCFILE := main.c
SRCPATH := ./src/
SRCS := $(addprefix $(SRCPATH), $(SRCFILE))
HEADERS := ./include/
OBJS := $(SRCS:.c=.o)
CC := cc
RM := rm -f
CFLAGS := -g -Wall -Wextra -Werror -I $(HEADERS)

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
