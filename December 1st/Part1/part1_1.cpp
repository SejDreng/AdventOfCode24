#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

int part1(){
    std::string line;
    std::ifstream file("input.txt");
    std::vector<int> numbers_colum1;
    std::vector<int> numbers_colum2;
    

    while(std::getline(file, line)){
        int number1 = std::stoi(line.substr(0, line.find(" ")));
        int number2 = std::stoi(line.substr(line.find(" ")+1, line.size()));
        numbers_colum1.push_back(number1);
        numbers_colum2.push_back(number2);
    }

    std::sort(numbers_colum1.begin(), numbers_colum1.end());
    std::sort(numbers_colum2.begin(), numbers_colum2.end());

    int tot_dist = 0;
    for(int i = 0; i < numbers_colum1.size(); i++){
        tot_dist += abs(numbers_colum1[i] - numbers_colum2[i]);
    }

    std::cout << tot_dist << std::endl;
    return 0;
}