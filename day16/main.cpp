#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <tuple>

/* 1. Initialization: Start by assigning a distance value to every vertex in the graph. Set the initial vertex’s distance as 0 and all others as infinity. Maintain a priority queue to keep track of vertices yet to be visited.

2. Exploration: While there are unvisited vertices:
— Choose the vertex with the smallest distance from the source vertex.
— Explore its neighboring vertices and update their distances if a shorter path is found from the source.

3. Optimal Path Retrieval: Once all vertices have been visited or their shortest paths have been determined, the algorithm provides the shortest path from the source to any destination vertex.
*/


const int INF = 1e9;
const int TURN_COST = 1000;


/*Keeping track of the actual direction since the cost of the next move depends if we need to turn*/
struct State {
    int x, y;   // Position actuelle dans la grille
    int dir;    // Direction actuelle (0 = haut, 1 = droite, 2 = bas, 3 = gauche)
    int cost;   // Coût total pour atteindre cet état

    bool operator>(const State& other) const {
    return cost > other.cost;
    }

};

void parse_input(std::vector<std::string> grid);

const std::vector<std::pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};



void print_vector(std::vector<std::string> vec)
{

    if (vec.empty())
        std::cout << "Empty" << std::endl;
    else
    {
    	for (std::string num : vec) 
		    std::cout << num << "\n";
    }

}


int main()
{

	std::vector<std::string> input;

	std::ifstream inputFile("input.txt");
    //std::ifstream inputFile("mininput.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::string line;

	while (getline(inputFile, line)) {
		input.push_back(line);
	}

	inputFile.close();

    print_vector(input);

    parse_input(input);
}

std::pair<int,int> find_start(std::vector<std::string> grid)
{
    std::pair<int,int> start_pos;

    for (int i = 0; i < int(grid.size()); i++)
    {
        for (int j = 0; j < int(grid[i].size()); j++)
        {
            if (grid[i][j] == 'S')
            {
                start_pos.first = i;
                start_pos.second = j; 
            }
        }
    }
    return (start_pos);
}

std::pair<int,int> find_end(std::vector<std::string> grid)
{
    std::pair<int,int> end_pos;

    for (int i = 0; i < int(grid.size()); i++)
    {
        for (int j = 0; j < int(grid[i].size()); j++)
        {
            if (grid[i][j] == 'E')
            {
                end_pos.first = i;
                end_pos.second = j; 
            }
        }
    }
    return (end_pos);
}

bool is_valid(int x, int y, std::vector<std::string> grid)
{
    return x >= 0 && y >= 0 && x < int(grid.size()) && y < int(grid[0].size()) && grid[x][y] != '#';
}

int dijkstra(std::vector<std::string> grid, int start_x, int start_y, int end_x, int end_y)
{
    int n = int(grid.size());
    int m = int(grid[0].size());

    // Tableau des coûts (x, y, direction)
    std::vector<std::vector<std::vector<int>>> cost(n, std::vector<std::vector<int>>(m, std::vector<int>(4, INF)));

    // Priority queue pour Dijkstra
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    
    // for (int dir = 0; dir < 4; ++dir) {
    //     pq.push({start_x, start_y, dir, 0});
    //     cost[start_x][start_y][dir] = 0;
    // }
        cost[start_x][start_y][1] = 0;
        pq.push({start_x, start_y, 1, 0});


        while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        // Si on atteint la destination
        if (current.x == end_x && current.y == end_y) {
            return current.cost;
        }

        // Si un chemin moins coûteux a été trouvé, ignorer ce chemin
        if (current.cost > cost[current.x][current.y][current.dir]) {
            continue;
        }

        // Explorer les voisins
        for (int new_dir = 0; new_dir < 4; ++new_dir) {
            int new_x = current.x + DIRECTIONS[new_dir].first;
            int new_y = current.y + DIRECTIONS[new_dir].second;

            if (is_valid(new_x, new_y, grid)) {
                int new_cost = current.cost + 1 + (new_dir != current.dir ? TURN_COST : 0);

                if (new_cost < cost[new_x][new_y][new_dir]) {
                    cost[new_x][new_y][new_dir] = new_cost;
                    pq.push({new_x, new_y, new_dir, new_cost});
                }
            }
        }
    }

    return -1; // Pas de chemin trouvé
}

void parse_input(std::vector<std::string> grid)
{
    std::pair<int,int> start_pos, end_pos;
    start_pos = find_start(grid);
    end_pos = find_end(grid);

    std::cout << "Starting position : (" << start_pos.first << "," << start_pos.second << ")" << std::endl;
    std::cout << "End position : (" << end_pos.first << "," << end_pos.second << ")" << std::endl;


    int result = dijkstra(grid, start_pos.first, start_pos.second, end_pos.first, end_pos.second);

    if (result != -1) {
        std::cout << "Le coût minimum est : " << result << std::endl;
    } else {
        std::cout << "Pas de chemin trouvé." << std::endl;
    }
    //for compilation
}