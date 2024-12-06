#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>
#include <bits/stdc++.h>


std::multimap<int, int> rulebook;

void create_rulebook(std::vector<std::string>& rules){
    std::regex pattern(R"((\d+))");
    std::smatch match;
    std::string rule;
    for (int i = 0; i < rules.size()-1; i++) {
        rule = rules[i];

        std::sregex_iterator it_1(rule.begin(), rule.end(), pattern);
        std::sregex_iterator it_end;
        std::smatch match_1 = *it_1;
        int number1= std::stoi(match_1[0]);;
        it_1++;
        match_1 = *it_1;
        int number2 = std::stoi(match_1[0]);
        rulebook.insert({number1, number2});
    }
    rules.clear();
}

bool is_valid(const std::string rule){
    std::regex pattern(R"((\d+))");
    std::smatch match;
    std::vector<int> rule_int;
    std::sregex_iterator it(rule.begin(), rule.end(), pattern);
    std::sregex_iterator it_end;
    while (it != it_end) {
        match = *it;
        int current_int = std::stoi(match[0]);
        auto range = rulebook.equal_range(current_int);
        for (auto it = range.first; it != range.second; it++) {
            int cnt = count(rule_int.begin(), rule_int.end(), it->second);
            if (cnt > 0) {
                return false;
            }
        }
        rule_int.push_back(std::stoi(match[0]));
        it++;
    }
    return true;
}

int find_middle_value(const std::string rule){
    std::regex pattern(R"((\d+))");
    std::smatch match;
    std::vector<int> rule_int;
    std::sregex_iterator it(rule.begin(), rule.end(), pattern);
    std::sregex_iterator it_end;
    while (it != it_end) {
        match = *it;
        rule_int.push_back(std::stoi(match[0]));
        it++;
    }
    return rule_int[rule_int.size()/2];
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
            create_rulebook(lines);
        }
    }
    file.close();
    
    std::vector<int> valid_lines_middle_num;
    for (int line_number = 0; line_number < lines.size(); line_number++) {
        if (is_valid(lines[line_number])) {
            valid_lines_middle_num.push_back(find_middle_value(lines[line_number]));
        }
    }
    int sum = std::accumulate(valid_lines_middle_num.begin(), valid_lines_middle_num.end(), 0);
    std::cout << sum << std::endl;

    return 0;
}