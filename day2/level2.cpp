/*The levels are either all increasing or all decreasing.
Any two adjacent levels differ by at least one and at most three.*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

void printVector(std::vector<std::vector<int>> vec);
int check_safes(std::vector<std::vector<int>> vec);
bool check_individual(const std::vector<int>& vec);
bool Dampener(const std::vector<int>& vec);


void printVector(std::vector<std::vector<int>> vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		const std::vector<int>& lineNumbers = vec[i];
		std::cout << "Ligne " << i + 1 << " : ";

		for (int n : lineNumbers)
			std::cout << n << " ";

		std::cout << std::endl;
	}

}

void printIndividualVector(std::vector<int> vec)
{

	for (int n : vec)
		std::cout << n << " ";

	std::cout << std::endl;


}

int check_safes(std::vector<std::vector<int>> vec)
{
	int count = 0;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		const std::vector<int>& lineNumbers = vec[i];
		if (check_individual(lineNumbers))
			count++;
		else
		{
			if (Dampener(lineNumbers))
			count++;
		}
	}
	return count;
}

bool check_individual(const std::vector<int>& vec)
{
	using std::begin;
	using std::end;

	bool isIncreasing = std::is_sorted(begin(vec), end(vec)); //croissant
	bool isDecreasing = std::is_sorted(begin(vec), end(vec), std::greater<int>()); //decroissant

	if (!isIncreasing && !isDecreasing) {
		return false;
	}

	//diff between levels must be [1-3]
	for (size_t i = 0; i < vec.size() - 1; ++i)
	{
		int diff = std::abs(vec[i] - vec[i + 1]);
		if (diff < 1 || diff > 3)
			return false;

	}

	//printIndividualVector(vec);


	return (true);
}


bool Dampener(const std::vector<int>& vec)
{
	using std::begin;
    using std::end;


	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::vector<int> modifiedVec = vec;
		modifiedVec.erase(modifiedVec.begin() + i);

		if (check_individual(modifiedVec))
			return true;

	}


	return false;
}




int main()
{
	int safe_report = 0;

	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::vector<std::vector<int>> allLines;
	std::string line;

	while (std::getline(inputFile, line))
	{
		std::vector<int> numbers;
		std::stringstream ss(line);
		int num;
		while (ss >> num)
			numbers.push_back(num);
		allLines.push_back(numbers);
	}
	inputFile.close();
	//printVector(allLines);

	safe_report = check_safes(allLines);
	std::cout << "Number of safe reports : " << safe_report;
	return 0;

}




