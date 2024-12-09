#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>

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

    if (getline(inputFile, line))
		std::cout << line << std::endl;
	else
		std::cerr << "Fichier vide ou erreur" << std::endl;

	inputFile.close();

	parse_input(line);
    
	return 0;
}

void parse_input(std::string input)
{

	int index = 0;
	std::string blocks;

	for (long unsigned int i = 0; i < input.length(); i++)
	{
		if (i % 2 == 0) //pair
		{
			std::string index_string = index - '0';
			for (int j = 0; j < input[i] ; j++)
				blocks.push_back(index_string);
			index++;
		}
		else 
		{
			for (int j = 0; j < input[i] ; j++)
				blocks.push_back('.');
		}

	}
	std::cout << blocks << std::endl;
}