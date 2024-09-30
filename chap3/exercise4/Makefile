CC = g++
TARGET = Rational
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -std=c++20 -g -o $(TARGET) $^

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

