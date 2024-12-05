#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>


int countXMAS(const std::vector<std::string>& grid);
bool checkWord(const std::vector<std::string>& grid, int x, int y, int dx, int dy);
bool checkWordX(const std::vector<std::string>& grid, int x, int y);
int countX_MAS(const std::vector<std::string>& grid);

const int directions[8][2] =
{
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
	{1, 1},
	{1, -1},
	{-1, 1},
	{-1, -1}
};

int main()
{

	std::vector<std::string> grid;

	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::string line;

	while (getline(inputFile, line)) {
		grid.push_back(line);
	}

	inputFile.close();



	int count = countXMAS(grid);
	int count_t2 = countX_MAS(grid);


	std::cout << " Task one : " << count << std::endl;
	std::cout << " Task two : " << count_t2 << std::endl;

	return 0;
}


bool checkWord(const std::vector<std::string>& grid, int x, int y, int dx, int dy)
{
	std::string word = "XMAS";
	int rows = grid.size(), cols = grid[0].size();

	for (long unsigned int i = 0; i < word.size(); i++)
	{
		int nx = x +i *dx;
		int ny = y +i *dy;
		if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
			return false;
		if (grid[nx][ny] != word[i])
			return false;

	}
	return true;
}

int countXMAS(const std::vector<std::string>& grid)
{
	int rows = grid.size();
	int cols = grid[0].size();
	int count = 0;

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (grid[x][y] == 'X')
			{
				for (const auto &dir : directions)
				{
					int dx = dir[0];
					int dy = dir[1];
					if (checkWord(grid, x, y, dx, dy))
						count++;
				}
			}
		}
	}
	return count;
}

int countX_MAS(const std::vector<std::string>& grid)
{
	int rows = grid.size();
	int cols = grid[0].size();
	int count = 0;

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (grid[x][y] == 'A')
			{
				if (checkWordX(grid, x, y))
					count++;
			}
		}


	}
	return count;
}

bool isMAS(const std::string& diag, const std::string& word) {
	return diag == word || diag == std::string(word.rbegin(), word.rend());
}


bool checkWordX(const std::vector<std::string>& grid, int x, int y)
{

	std::string word = "MAS";
	int rows = grid.size(), cols = grid[0].size();

	// int nx;//= x +i *dx;
	// int ny;// = y +i *dy;
	std::string diag1,diag2;


	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < rows && y + 1 < cols) {
		diag1 += grid[x + 1][y - 1]; // Bas gauche
		diag1 += grid[x][y];         // Centre
		diag1 += grid[x - 1][y + 1]; // Haut droit
	}

	// Deuxième diagonale (descendante)
	if (x - 1 >= 0 && y + 1 < cols && x + 1 < rows && y - 1 >= 0) {
		diag2 += grid[x - 1][y - 1]; // Haut gauche
		diag2 += grid[x][y];         // Centre
		diag2 += grid[x + 1][y + 1]; // Bas droit
	}

    // Vérifier si chaque diagonale est un MAS
	return isMAS(diag1, word) && isMAS(diag2, word);
}

	// //S
	// int nx = x + 0;
	// int ny = y + 2;
	// if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
	// 		return false;
	// if (grid[nx][ny] != word[2])
	// 	return false;

	// nx = x + 2;
	// ny = y + 2;
	// if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
	// 		return false;
	// if (grid[nx][ny] != word[2])
	// 	return false;


	// //A
	// nx = x + 1;
	// ny = y + 1;
	// if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
	// 		return false;
	// if (grid[nx][ny] != word[1])
	// 	return false;

	// //M
	// nx = x + 2;
	// ny = y + 0;
	// if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
	// 		return false;
	// if (grid[nx][ny] != word[0])
	// 	return false;

// 	return true;
// }

