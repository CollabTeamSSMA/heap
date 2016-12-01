CC = g++
CFLAGS = -c -Wall
OFLAG = -o
TARGET = heap
all: $(TARGET)
$(TARGET):main.o
	$(CC) main.o $(OFLAG) $(TARGET)
main.o:main.cpp heap.h
	$(CC) main.cpp $(CFLAGS)
clean:
	rm *~ *.o $(TARGET)
