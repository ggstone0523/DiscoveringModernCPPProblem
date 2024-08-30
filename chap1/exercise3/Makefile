CC = g++
TARGET = Answer
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test clean

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	./$(TARGET) 3

clean:
	rm -rf $(TARGET)

