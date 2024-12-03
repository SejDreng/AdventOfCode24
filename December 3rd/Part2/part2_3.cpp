#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>


int part2(){
    std::string line;
    std::ifstream file("input.txt");
    std::regex pattern1(R"(don't\(\)|mul\((\d+),(\d+)\)|do\(\))");
    
    int tot = 0;
    bool do_flag = true;
    bool dont_flag = false;

    while(std::getline(file, line)){

        std::sregex_iterator it_1(line.begin(), line.end(), pattern1);
        std::sregex_iterator it_end;
        while (it_1 != it_end){

            std::smatch match_1 = *it_1;

            if(match_1[0] == "do()"){
                do_flag = true;
                dont_flag = false;
                it_1++;
                continue;
            }
            else if(match_1[0] == "don't()"){
                do_flag = false;
                dont_flag = true;
                it_1++;
                continue;
            }
            if(do_flag){
                try {
                    int num1 = std::stoi(match_1[1].str());
                    int num2 = std::stoi(match_1[2].str());
                    tot += num1 * num2;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid argument: " << e.what() << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Out of range: " << e.what() << std::endl;
                }
            }
            it_1++;
        }
    }

    std::cout << tot << std::endl;
    return 0;   
}