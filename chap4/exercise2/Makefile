CC = g++
TARGET = FindIf
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -g -std=c++20 -o $(TARGET) $^

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

