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
	int total_distance;
	total_distance = 0;

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

	int size = left.size();
	int sub_dist;

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	// print_vector(left);
	// print_vector(right);

	for (int i = 0; i < size; i++)
	{
		sub_dist = abs(left[i] - right[i]);
		total_distance += sub_dist;

	}

	std::cout << "Total distance : " << total_distance << std::endl;


}


