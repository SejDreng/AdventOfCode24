#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>



std::map<int, int> rulebook;

void create_rulebook(std::vector<std::string>& rules){
    std::regex pattern(R"((\d+))");
    std::smatch match;
    std::string rule;
    for (int i = 0; i < rules.size(); i++) {
        rule = rules[i];
        std::sregex_iterator it_1(rule.begin(), rule.end(), pattern);
        std::sregex_iterator it_end;
        int number1;
        int number2;
        std::cout << "Creating rulebook" << std::endl;

        while (it_1 != it_end){
            std::smatch match_1 = *it_1;
            std::cout << match_1[0] << std::endl;
        }


    }
    rules.clear();

}


int part1(){
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file.\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
        if (line.size() == 0) {
            std::cout << "Creating rulebook" << std::endl;
            create_rulebook(lines);
        }
    }
    file.close();

    int tot = 0;
    for (int line_number = 0; line_number < lines.size(); line_number++) {
        continue;
    }
    std::cout << tot << std::endl;

    return 0;
}