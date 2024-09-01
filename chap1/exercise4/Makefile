CC = g++
TARGET = Answer
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test clean

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	./$(TARGET) 1.4142 3.1415 2.7182
	./$(TARGET) 1.4142 2.7182 3.1415
	./$(TARGET) 2.7182 3.1415 1.1412
	./$(TARGET) 2.7182 1.1412 3.1415
	./$(TARGET) 3.1415 1.1412 2.7182
	./$(TARGET) 3.1415 2.7182 1.1412
	./$(TARGET) 3.1415 1.1412 1.1412

clean:
	rm -rf $(TARGET)

