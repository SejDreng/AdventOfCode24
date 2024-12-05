#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>



bool check_other_line2(std::vector<std::string>& lines, int lineNum, int indx, char letter) {
    if (lineNum < 0 || lineNum >= lines.size()){ 
        return false;
    }
    if (indx < 0 || indx >= lines[lineNum].size()){ 
        return false;
    }
    return lines[lineNum][indx] == letter; 
}


bool double_checker(std::vector<std::string>& lines, int lineNum, int indx, char letter){

    std::vector<std::vector<int>> indexing_matrix = {{-1,-1},  {-1,1},   {1,1},   {1,-1}};

    for(int i = 0; i < indexing_matrix.size(); i++){
        if(check_other_line2(lines, lineNum + indexing_matrix[i][0], indx + indexing_matrix[i][1], letter) && check_other_line2(lines, lineNum + indexing_matrix[(i+1)%4][0], indx + indexing_matrix[(i+1)%4][1], letter)){
            std::cout << "Found at " << indexing_matrix[i][0] << " " << indexing_matrix[i][1] << std::endl;
            std::cout << "and " << indexing_matrix[(i+1)%4][0] << " " << indexing_matrix[(i+1)%4][1] << std::endl;
            return true;
        }
    }
    return false;
}


int part2(){
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file.\n";
        return 1;
    }

    // Load all lines into memory
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close(); // Close the file after reading


    int tot = 0;
    for (int line_number = 0; line_number < lines.size(); line_number++) {
        const std::string& line = lines[line_number];
        for (int j = 0; j < line.size(); j++){
            if (line[j] == 'A'){
                if(double_checker(lines, line_number, j, 'M') && double_checker(lines, line_number, j, 'S')){
                    tot++;
                }
            }
        }
    }
    std::cout << tot << std::endl;

    return 0;
}