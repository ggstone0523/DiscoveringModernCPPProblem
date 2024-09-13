CC = g++
TARGET = Rational
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -fcompare-debug-second -g -o $(TARGET) $^

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

