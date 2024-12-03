#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

int main()
{

	int sum;

	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string fileContent = buffer.str();

	//std::cout << "File content : "<< fileContent;
	inputFile.close();

	std::regex mul_regex(R"(mul\((\d+),(\d+)\))");
	std::smatch match;

	sum = 0;

	std::string::const_iterator searchStart(fileContent.cbegin());
	while (std::regex_search(searchStart, fileContent.cend(), match, mul_regex))
	{
		int num1 = std::stoi(match[1].str());
		int num2 = std::stoi(match[2].str());

		sum += (num1 * num2);

		searchStart = match.suffix().first;
	}

	std::cout << "Sum : " << sum;
	// if (std::regex_search(fileContent, match, mul_regex))
	// {
	// 	std::cout << "Nombre 1 : " << match[1] << "\n";
	// 	std::cout << "Nombre 2 : " << match[2] << "\n";
	// 	sum += (match[1] * match[2]);
	// }
	//std::regex mul_regex(R"(mul\(\d+,\d+\))"); //can't take the two matches

}


/*
REGEX :

R : raw string : les caractères spéciaux comme \ n'ont pas besoin d'être échappés dans la chaîne elle-même.
\( = caractere literal (
\d+ = un chiffre ou plusieurs
,

*/
