#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

bool is_safe_unmodified(std::vector<int> numbers){
    int temp_inc = 0;
    int temp_dec = 0;
    for (int i = 1 ; i < numbers.size(); i++){
        if (numbers[i] > numbers[i-1] && numbers[i] < numbers[i-1]+4){
            temp_inc++;
        }
        else{
            break;
        }
    }
    for (int i = 1 ; i < numbers.size(); i++){
        if (numbers[i] < numbers[i-1] && numbers[i] > numbers[i-1]-4){
            temp_dec++;
        }
        else{
            break;
        }
    }
    if (temp_inc == numbers.size()-1 || temp_dec == numbers.size()-1){
        return true;
    }
    return false;
}

bool is_safe_modified(std::vector<int> numbers){
    for (int i = 0; i < numbers.size(); i++){
        int temp = numbers[i];
        numbers.erase(numbers.begin()+i);
        if (is_safe_unmodified(numbers)){
            return true;
        }
        numbers.insert(numbers.begin()+i, temp);
    }
    return false;
}


int part2(){
    std::string line;
    std::ifstream file("input.txt");
    int safe_lists = 0;
    while(std::getline(file, line)){
        std::vector<int> numbers;
        size_t pos = 0; 
        while (pos < line.size()) {

            while (pos < line.size() && line[pos] == ' ') {
                ++pos;
            }

            size_t endPos = pos;
            while (endPos < line.size() && line[endPos] != ' ') {
                ++endPos;
            }

            if (pos < endPos) {
                numbers.push_back(std::stoi(line.substr(pos, endPos - pos)));
            }

            pos = endPos;
        }
        
        if (is_safe_unmodified(numbers) || is_safe_modified(numbers)){
            safe_lists++;
        }

        

    }
    std::cout << safe_lists << std::endl;
    return 0;
}