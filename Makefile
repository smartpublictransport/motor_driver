CFLAGS = -c -g -Wall -fPIC
LIBNAME = libmotor_driver.so 
LIBPATH = ~/pod/lib
CC = g++
SRC = motor.cpp
OBJ = $(SRC:.cpp = .o)

lib: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)
	$(CC) -shared -o $(LIBNAME) *.o

install: $(LIBNAME)
	mv $(LIBNAME) $(LIBPATH)

clean:
	rm -f core *.o
