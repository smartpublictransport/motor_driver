CFLAGS = -O
CC = g++
SRC = motor.cpp
OBJ = $(SRC:.cpp = .o)

Test: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ)

clean:
	rm -f core *.o
