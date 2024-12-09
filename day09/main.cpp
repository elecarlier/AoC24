#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>


void print_vector(std::vector<std::string> vec)
{

    if (vec.empty())
        std::cout << "Empty" << std::endl;
    else
    {
    	for (std::string num : vec)
		{
			std::cout << num << " " ;
		}

    }

}
void parse_input(std::string input);

int main()
{
	//std::ifstream inputFile("input.txt");
	std::ifstream inputFile("mininput.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::string line;
	getline(inputFile, line);
	// if (getline(inputFile, line))
	// 	std::cout << line << std::endl;
	// else
	// 	std::cerr << "Fichier vide ou erreur" << std::endl;

	inputFile.close();
	std::cout << line << std::endl;
	parse_input(line);

	return 0;
}

void parse_input(std::string input)
{
	int index = 0;
	//std::string blocks;
	std::vector<std::string> blocks;
	std::string index_as_string;

	for (int i = 0; i < int(input.length()); i++)
	{
		if (i % 2 == 0) //pair
		{
			std::stringstream stream;
			stream << index;
			stream >> index_as_string;
			int j = 0;
			while (j < (input[i]- '0'))
			{
				blocks.push_back(index_as_string);
				j++;
			}
			index++;
		}
		else
		{
			int j = 0;
			while (j < int(input[i] - '0'))
			{
				blocks.push_back("-1");
				j++;
			}
		}
	}
	print_vector(blocks);
}
