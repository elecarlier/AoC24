#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

void print_vector_int(vector<vector<int>> numbersLines);
bool check_temp(vector<pair<int, int>> pairs, vector<int> vec);
void check_invalid(vector<pair<int, int>> pairs, vector<vector<int>> numbersLines);
void calc_res(vector<vector<int>> valid);

int main() {
	vector<pair<int, int>> pairsLines;
	vector<vector<int>> numbersLines;

	ifstream inputFile("input.txt");

	if (!inputFile) {
		cerr << "Erreur d'ouverture du fichier!" << endl;
		return 1;
	}

	string line;

	// Lecture de la première partie (paires de nombres séparées par '|')
	while (getline(inputFile, line) && !line.empty()) {
		stringstream pairStream(line);
		string left, right;

		while (getline(pairStream, left, '|') && getline(pairStream, right))
			pairsLines.push_back(make_pair(stoi(left), stoi(right)));
	}

	while (getline(inputFile, line))
	{
		stringstream numStream(line);
		vector<int> currentLineNumbers;
		string num;

		while (getline(numStream, num, ','))
			currentLineNumbers.push_back(stoi(num));
		numbersLines.push_back(currentLineNumbers);
	}

	inputFile.close();


	//print_vector_int(numbersLines);

	check_invalid( pairsLines, numbersLines );

	return 0;
}



void print_vector_int(vector<vector<int>> numbersLines)
{
	cout << "\nNombres par ligne:" << endl;
	for (const auto& line : numbersLines) {
		for (int num : line) {
			cout << num << " ";
	}
	cout << endl;
    }
}

void check_invalid(vector<pair<int, int>> pairs, vector<vector<int>> numbersLines)
{
	vector<vector<int>> valid;
	for (vector<vector<int>>::iterator lineIt = numbersLines.begin(); lineIt != numbersLines.end(); ++lineIt)
	{
		bool result = check_temp(pairs, *lineIt);
		if (result)
		{
			//cout << "Ligne valide!" << endl;
			valid.push_back(*lineIt);
		}
	}
	calc_res(valid);
}


void calc_res(vector<vector<int>> valid)
{
	int res = 0;

	cout << "size of valid : " << valid.size();
	for (vector<vector<int>>::iterator lineIt = valid.begin(); lineIt != valid.end(); ++lineIt) {
		vector<int> line = *lineIt;
		int middleIndex = line.size() / 2;
		res += line[middleIndex];
	}

	std::cout << "Somme des milieurs : " << res << endl;

}

bool check_temp(vector<pair<int, int>> pairs, vector<int> vec)
{
	vector<pair<int, int>> inval_pairs;
	(void)pairs;

	std::vector<int>::iterator			it;
	std::vector<int>::iterator			jt;
	for (it = vec.begin(); it != vec.end() ; it++)
	{
		for (jt = it + 1; jt != vec.end() ; jt++)
		{
			std::pair<int, int>	p(*jt , *it);
			inval_pairs.push_back(p);
		}
	}
	// cout << "inval_pairs: ";
	// for (const auto& pair : inval_pairs) {
	// 	cout << "(" << pair.first << ", " << pair.second << ") ";
	// }
	// cout << endl;

	for (const auto& inval_pair : inval_pairs)
	{
		if (find(pairs.begin(), pairs.end(), inval_pair) != pairs.end())
			return false;
	}
	return true;
}
