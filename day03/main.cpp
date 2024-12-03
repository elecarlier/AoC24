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
	std::regex dont_regex(R"(don't\(\))");
	std::regex do_regex(R"(do\(\))");
 	std::regex combined_regex(R"(do\(\)|don't\(\)|mul\(\d+,\d+\))");

	std::sregex_iterator iter(fileContent.begin(), fileContent.end(), combined_regex);
	std::sregex_iterator end;

	bool mul_enabled = true;
	sum = 0;

	while (iter != end)
	{
		std::string match = iter->str();
		if (std::regex_match(match, do_regex))
			mul_enabled = true;
		else if (std::regex_match(match, dont_regex))
			mul_enabled = false;
		else if (std::regex_match(match, mul_regex))
		{
			std::smatch mul_match;
			if (mul_enabled)
			{
				if (std::regex_match(match, mul_match, mul_regex))
				{
					int num1 = std::stoi(mul_match[1].str());
					int num2 = std::stoi(mul_match[2].str());
					sum += (num1 * num2);
				}

			}
		}
		iter++;
	}


	std::cout << "Sum : " << sum;

}


/*
REGEX :

R : raw string : les caractères spéciaux comme \ n'ont pas besoin d'être échappés dans la chaîne elle-même.
\( = caractere literal (
\d+ = un chiffre ou plusieurs
,

*/
