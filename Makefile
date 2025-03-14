CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -w -pthread -Iinclude -arch arm64 -I/opt/homebrew/Cellar/duckdb/1.2.1/include -L/opt/homebrew/Cellar/duckdb/1.2.1/lib 
LDFLAGS = -lduckdb
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = flock_project

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
