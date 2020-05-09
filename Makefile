#
# CXX := g++
# CXXFLAGS := -std=c++17 -lglew -framework OpenGL -lglfw
#
# OBJECTS := main.o core.o systems.o demo.o
#
# all: $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) *.o -o ./compile/outRelease
#
# main.o: *.cpp
# 	$(CXX) $(CXXFLAGS) *.cpp
# core.o: core/*.cpp
# 	$(CXX) $(CXXFLAGS) -c core/*.cpp
# systems.o: core/systems/*.cpp
# 	$(CXX) $(CXXFLAGS) -c core/systems/*.cpp
# demo.o: demo/*.cpp
# 	$(CXX) $(CXXFLAGS) -c demo/*.cpp
# clean:
# 	rm -f *.o
all:
		g++ -o ./compile/outRelease *.cpp core/*.cpp core/systems/*.cpp demo/*.cpp -std=c++17 -lglew -framework OpenGL -lglfw
