CC = g++
TARGET = Polynomial
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	valgrind ./$(TARGET)

clean:
	rm -rf $(TARGET)

