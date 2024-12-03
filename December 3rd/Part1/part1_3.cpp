#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>


int part1(){
    std::string line;
    std::ifstream file("input.txt");
    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    int tot = 0;
    while(std::getline(file, line)){
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator it_end;
        while (it != it_end){
            std::smatch match = *it;
            tot += std::stoi(match[1].str()) * std::stoi(match[2].str());
            it++;
        }
    }
    std::cout << tot << std::endl;
    return 0;   
}