CC = g++
CFLAGS = -Wall -Wextra -std=c99 -lm
LDFLAGS = -lglut -lGL -lGLU

SRC = main.cpp
OBJ = $(SRC:.c=.o)
EXEC = sistema_solar

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)