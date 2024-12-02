/*The levels are either all increasing or all decreasing.
Any two adjacent levels differ by at least one and at most three.*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>



int main()
{
	//int safe_files = 0;

	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}
	

	std::string line;

	while (std::getline(inputFile, line))
	{
		std::cout << line <<std::endl;
	}
}
