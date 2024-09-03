CC = g++
TARGET = Answer
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	valgrind ./$(TARGET) > resultOfValgrind.txt 2>&1
	cat resultOfValgrind.txt

clean:
	rm -rf $(TARGET)
