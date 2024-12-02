#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

int part2(){
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

    int tot = 0;
    for(int i = 0; i < numbers_colum1.size(); i++){
        int counter = 0;
        for (int j = 0; j < numbers_colum2.size(); j++){
            if (numbers_colum1[i] == numbers_colum2[j]){
                counter++;
            }
        }
        tot += (counter*numbers_colum1[i]);
    }
    std::cout << tot << std::endl;
    return 0;
}

