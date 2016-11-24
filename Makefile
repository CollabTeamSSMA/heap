CC = g++
CFLAGS = -c -Wall
OFLAG = -o
TARGET = heap
all: $(TARGET)
$(TARGET): main.o heap.o
	$(CC) main.o heap.o $(OFLAG) $(TARGET)
main.o: main.cpp heap.h
	$(CC) main.cpp $(CFLAGS)
heap.o: heap.cpp heap.o
	$(CC) heap.cpp $(CFLAGS)
clean:
	rm *~ $(TARGET) *.o
