CC = g++
TARGET = JuliaMandel
SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^ `sdl2-config --cflags --libs`

test:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

