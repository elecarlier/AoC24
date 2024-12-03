#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>


void print_vector(std::vector<int> vec)
{
	for (int num : vec) {
		std::cout << num << "\n";
	}
}

int main()
{
	int total;
	total = 0;

	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::vector<int> left;
	std::vector<int> right;

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		int leftNumber, rightNumber;
		if (ss >> leftNumber >> rightNumber)
		{
			left.push_back(leftNumber);
			right.push_back(rightNumber);
		}
	}
	inputFile.close();

	int left_size = left.size();
	int right_size = right.size();

	// sort(left.begin(), left.end());
	// sort(right.begin(), right.end());

	// print_vector(left);
	// print_vector(right);

	for (int i = 0; i < left_size ; i++)
	{
		int sub = 0;
		for (int j = 0; j < right_size; j++)
		{
			if (left[i] == right[j])
			{
				sub += 1;
			}


		}
		sub = sub * left[i];
		total += sub;
	}
	std::cout << "Total : " << total << std::endl;


}


