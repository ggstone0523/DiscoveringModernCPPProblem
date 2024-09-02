CC = g++
TARGET = WritePolygonData
SRCS = $(wildcard ./*.cpp) $(wildcard ../PolygonFormulaFolder/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
HEADERS = $(wildcard ./*.h) $(wildcard ../PolygonFormulaFolder/*.h)

all: build test

build: $(SRCS) $(HEADERS)
	$(CC) -g -o $(TARGET) $^

test:
	./$(TARGET) 3
	mv ./PolygonVolAndSurAreaData.txt ../

clean:
	rm -rf $(TARGET)

