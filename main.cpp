#include "core/runner.h"
#include "demo/myWorld.hpp"
#include <iostream>


int main(){
    MyWorld newWorld;
	std::cout << "Running capstone demo..." << std::endl;
	return run(newWorld, "demo/gameLevel3.txt");
}
