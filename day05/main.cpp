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
void calc_res(vector<vector<int>> valid, bool task);
vector<int> check_and_swap(vector<pair<int, int>> pairs, vector<int>& vec);
void task2(vector<pair<int, int>> pairs, vector<vector<int>> invalid);

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
	vector<vector<int>> invalid;
	for (vector<vector<int>>::iterator lineIt = numbersLines.begin(); lineIt != numbersLines.end(); ++lineIt)
	{
		bool result = check_temp(pairs, *lineIt);
		if (result)
			valid.push_back(*lineIt);
		else
			invalid.push_back(*lineIt);

	}

	calc_res(valid, 1);
	task2(pairs, invalid);
}

void task2(vector<pair<int, int>> pairs, vector<vector<int>> invalid)
{
	vector<vector<int>> new_valid;
	vector<int> temp;
	for (vector<vector<int>>::iterator lineIt = invalid.begin(); lineIt != invalid.end(); ++lineIt)
	{
		temp = check_and_swap(pairs, *lineIt);
		new_valid.push_back(temp);

	}
	calc_res(new_valid, 0);

}

void calc_res(vector<vector<int>> valid, bool task)
{
	int res = 0;

	for (vector<vector<int>>::iterator lineIt = valid.begin(); lineIt != valid.end(); ++lineIt) {
		vector<int> line = *lineIt;
		int middleIndex = line.size() / 2;
		res += line[middleIndex];
	}

	if (task)
		std::cout << "Task 1 : " << res << endl;
	else
		std::cout << "Task 2: " << res << endl;
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

	for (const auto& inval_pair : inval_pairs)
	{
		if (find(pairs.begin(), pairs.end(), inval_pair) != pairs.end())
			return false;
	}
	return true;
}

// vector<int> check_and_swap(vector<pair<int, int>> pairs, vector<int>& vec)
// {
// 	vector<pair<int, int>> inval_pairs;

// 	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
// 	{
// 		for (vector<int>::iterator jt = it + 1; jt != vec.end(); ++jt)
// 		{
// 			pair<int, int> p(*it, *jt);
// 			inval_pairs.push_back(p);
// 		}
// 	}

// 	for (vector<pair<int, int>>::iterator inval_it = inval_pairs.begin(); inval_it != inval_pairs.end(); ++inval_it)
// 	{
// 		if (find(pairs.begin(), pairs.end(), *inval_it) == pairs.end()) {
// 			//cout << "Paire invalide trouvée: (" << inval_it->first << ", " << inval_it->second << ")" << endl;
// 			vector<int>::iterator it1 = find(vec.begin(), vec.end(), inval_it->first);
// 			vector<int>::iterator it2 = find(vec.begin(), vec.end(), inval_it->second);

// 			if (it1 != vec.end() && it2 != vec.end())
// 				swap(*it1, *it2);

// 	}
// 	}
// 	return vec;
// }

vector<int> check_and_swap(vector<pair<int, int>> pairs, vector<int>& vec)
{
	vector<pair<int, int>> inval_pairs;

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		for (vector<int>::iterator jt = it + 1; jt != vec.end(); ++jt)
		{
			pair<int, int> p(*it, *jt);
			inval_pairs.push_back(p);
		}
	}

	// Reorder the invalid pairs
	sort(vec.begin(), vec.end(), [&pairs](int a, int b)
	{
		for (const auto& pair : pairs) {
			if (pair.first == a && pair.second == b)
				return true;
			if (pair.first == b && pair.second == a)
				return false;
		}
		return false; // If no pair found, maintain order
	});

	return vec;
}
