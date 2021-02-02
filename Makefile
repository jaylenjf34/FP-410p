CXX = g++
CXXFLAGS = -g -Wall -Werror
TARGET = frupal
SRCS = frupal.cpp game.cpp map.cpp menu.cpp player.cpp item.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) -lncurses

clean:
	-rm -f $(TARGET)
