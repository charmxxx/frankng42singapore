TARGET := ft_display_file
SRCFILE := main.c
SRCPATH := ./src/
SRCS := $(addprefix $(SRCPATH), $(SRCFILE))
HEADER := ./include/
AR := ar rcs
RM := rm -f
CC := cc
CFLAGS := -Wall -Wextra -Werror -I ${HEADER}
OBJS := $(SRCS:.c=.o)

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
