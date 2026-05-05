# 1. Configuration
TARGET   = demo_app
CC       = gcc
CFLAGS   = -Wall -Wextra -Iinclude -g   # -Iinclude tells GCC to look in 'include' for .h files
LDFLAGS  = 

# 2. Finding Files
# This finds demo.c PLUS everything in the src directory
SRCS     = demo.c $(wildcard src/*.c)
OBJS     = $(SRCS:.c=.o)

# 3. Main Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule for files in the root (like demo.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for files in the src/ folder
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
