#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>

using PairVec = std::vector<std::pair<int, int>>;
void parse_input(const std::vector<std::string>& grid);
void print_vector(std::vector<std::string> vec);
void calc_antinodes(std::map<char, std::vector<std::pair<size_t, size_t>>> char_map, size_t row, size_t col);
void check_antinodes(std::vector<std::pair<size_t, size_t>>& vec_antinodes, size_t row, size_t col);



void print_vector(std::vector<std::string> vec)
{

    if (vec.empty())
        std::cout << "Empty" << std::endl;
    else
    {
    	for (std::string num : vec) 
		    std::cout << num << "\n";
    }

}


int main()
{

	std::vector<std::string> input;

	//std::ifstream inputFile("input.txt");
    std::ifstream inputFile("mini_input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::string line;

	while (getline(inputFile, line)) {
		input.push_back(line);
	}

	inputFile.close();

   // print_vector(input);

    parse_input(input);
}

void parse_input(const std::vector<std::string>& grid) {

    std::map<char, std::vector<std::pair<size_t, size_t>>> char_map;
    size_t size_row = grid.size();
    size_t size_col = grid[0].size();


    std::cout << "Size of row : " << size_row << " size of col : " << size_col << std::endl;


    for (size_t row = 0; row < grid.size(); ++row) { 
        const std::string& line = grid[row];
        for (size_t col = 0; col < line.size(); ++col) { 
            char c = line[col];
            if (std::isalpha(c) || std::isdigit(c)) {
                char_map[c].emplace_back(row, col);
            }
        }
    }


    for (const auto& [key, positions] : char_map) {
        std::cout << "Clé '" << key << "' : ";
        for (const auto& [row, col] : positions) {
            std::cout << "(" << row << ", " << col << ") ";
        }
        std::cout << '\n';
    }

    calc_antinodes(char_map, size_row, size_col );

}





void calc_antinodes(std::map<char, std::vector<std::pair<size_t, size_t>>> char_map, size_t row, size_t col)
{

    std::set<std::pair<size_t, size_t>> vec_antinodes;
    //std::pair<size_t, size_t> antinode;

    for (std::map<char, std::vector<std::pair<size_t, size_t>>>::iterator it = char_map.begin(); it != char_map.end(); ++it) {
        
        std::vector<std::pair<size_t, size_t>>& positions = it->second;

        for (std::vector<std::pair<size_t, size_t>>::iterator pos_it = positions.begin(); pos_it != positions.end(); ++pos_it) 
        {
            std::cout << std::endl << "Coordinate : (" << pos_it->first << ","<< pos_it->second << ") : ";
            for (std::vector<std::pair<size_t, size_t>>::iterator posbis_it = pos_it  + 1; posbis_it != positions.end(); ++posbis_it) 
            {
                std::cout << "(" << posbis_it->first << ","<< posbis_it->second << "), ";
                std::pair<size_t, size_t> antinode;
                int diff_x = abs( pos_it->first - posbis_it->first);
                int diff_y = abs( pos_it->second - posbis_it->second);

                std::cout << std::endl << "Deltas -> x :" <<  diff_x << " y : " << diff_y ;
                antinode.first = pos_it->first - diff_x;
                antinode.second = pos_it->second - diff_y;

                std::cout << std::endl << "Antinode: (" << antinode.first << ", " << antinode.second << ")" ;

                if (antinode.first < row && antinode.second < col)
                    vec_antinodes.insert(antinode);

                antinode.first = posbis_it->first + diff_x;
                antinode.second = posbis_it->second  + diff_y;

                std::cout << " (" << antinode.first << ", " << antinode.second << ")";

                if (antinode.first < row && antinode.second < col)
                    vec_antinodes.insert(antinode);
                
            }
        }
    }

     std::cout << "Number of antinodes : " << vec_antinodes.size() << std::endl;

    
    //check_antinodes(vec_antinodes, row, col);
    // for (std::vector<std::pair<size_t, size_t>>::iterator pos_it = vec_antinodes.begin(); pos_it != vec_antinodes.end(); ++pos_it)
    // {
    //     std::cout << "(" << pos_it->first << "," << pos_it->second << ")" ;
    // }

    


}

