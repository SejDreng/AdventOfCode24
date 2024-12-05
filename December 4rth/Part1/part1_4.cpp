#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>



bool check_other_line(std::vector<std::string>& lines, int lineNum, int indx, char letter) {
    if (lineNum < 0 || lineNum >= lines.size()){ 
        return false;
    }
    if (indx < 0 || indx >= lines[lineNum].size()){ 
        return false;
    }
    return lines[lineNum][indx] == letter; 
}


int part1(){
    std::ifstream file("input.txt");
    std::string xmas = "XMAS";

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

    std::vector<std::vector<int>> indexing_matrix = {{-1,-1}, {-1,0}, {-1,1},
                                                     {0,-1},          {0, 1},
                                                     {1,-1},  {1,0},  {1,1}};

    int tot = 0;
    for (int line_number = 0; line_number < lines.size(); line_number++) {
        const std::string& line = lines[line_number];
        for (int j = 0; j < line.size(); j++){
            if (line[j] == xmas[0]){
                for (int i = 0; i < indexing_matrix.size(); i++){
                    int index = j;
                    int line_number_search = line_number;
                    int xma = 1;
                    while(xma < xmas.size()){
                        index += indexing_matrix[i][0];
                        line_number_search += indexing_matrix[i][1];

                        if(!(check_other_line(lines, line_number_search, index, xmas[xma]))){
                            break;
                        }
                        xma++;
                    }
                    if (xma == xmas.size()){
                        tot++;
                    }
                }
            }
        }
    }
    std::cout << tot << std::endl;

    return 0;
}