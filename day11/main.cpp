#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <unordered_map>

/*
    If the stone is engraved with the number 0, it is replaced by a stone engraved with the number 1.
    If the stone is engraved with a number that has an even number of digits, it is replaced by two stones. The left half of the digits are engraved on the new left stone, and the right half of the digits are engraved on the new right stone. (The new numbers don't keep extra leading zeroes: 1000 would become stones 10 and 0.)
    If none of the other rules apply, the stone is replaced by a new stone; the old stone's number multiplied by 2024 is engraved on the new stone.
*/
//void applyrules(std::vector<std::string> input);

std::unordered_map<std::string, std::vector<std::string>> cache;

std::vector<std::string>  applyrulestask2(std::vector<std::string>& input);
std::vector<std::string>  applyrules(std::vector<std::string> input);

void print_vector(std::vector<std::string> vec)
{

    if (vec.empty())
        std::cout << "Empty" << std::endl;
    else
    {
    	for (std::string num : vec)
		{
			std::cout << num << " " ;
		}
    }

	std::cout << std::endl;
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
		std::istringstream stream(line);
		std::string number;

		while (stream >> number)
			input.push_back(number);
	}

	inputFile.close();

	std::cout << "Inital arrangement : " << std::endl;
	print_vector(input);
	

	for (int i = 0; i < 75; i++)
	{
		std::vector<std::string> new_vec;
		std::cout << std::endl << "Loop " << i + 1 << std::endl;
		new_vec = applyrulestask2(input);
		input = new_vec;
	}

    std::cout << "Task two : " << input.size();  
}

std::vector<std::string>  applyrulestask2(std::vector<std::string>& input)
{
	std::vector<std::string> new_vec;
	
	for (const std::string& num_str : input)
	{
		if (cache.find(num_str) != cache.end())
		{
			new_vec.insert(new_vec.end(), cache[num_str].begin(), cache[num_str].end());
			continue;
		}
		std::vector<std::string> transformed;
		long long num = std::stoll(num_str);
		if (num == 0)
		{
			transformed.push_back("1");
		}
			
		else if ( num_str.length() % 2 == 0)
		{
			size_t half = num_str.length()/2;
			std::string left = num_str.substr(0,half);
			std::string right = num_str.substr(half);
			left = std::to_string(std::stoll(left));
			right = std::to_string(std::stoll(right));
			transformed.push_back(left);
			transformed.push_back(right);
		}
		else 
		{

			long long int res = num * 2024;
			transformed.push_back(std::to_string(res));
		}
	cache[num_str] = transformed;
	new_vec.insert(new_vec.end(), transformed.begin(), transformed.end());
	}

	//print_vector(new_vec);
	return (new_vec);

}




std::vector<std::string>  applyrules(std::vector<std::string> input)
{
	std::vector<std::string> new_vec;
	
	for (const std::string& num_str : input)
	{
		long long num = std::stoll(num_str);
		if (num == 0)
		{
			//std::cout << "Number is " << num << " adding one to the vector" << std::endl;
			new_vec.push_back("1");
		}
			
		else if ( num_str.length() % 2 == 0)
		{
			//std::cout << "Number is " << num<< " and is even. " << std::endl;
			size_t half = num_str.length()/2;
			std::string left = num_str.substr(0,half);
			std::string right = num_str.substr(half);
			left = std::to_string(std::stoll(left));
			right = std::to_string(std::stoll(right));
			new_vec.push_back(left);
			new_vec.push_back(right);
			//std::cout << "Pushing back : " << left << std::endl;
			//std::cout << "Pushing back : " << right << std::endl;
		}
		else 
		{
			//std::cout << "Number is " << num << " and does not apply any rules. ";
			//std::stringstream stream;
			//long long int num;
			//stream << *it;
			//stream >> num;
			long long int res = num * 2024;
			//std::stringstream stream;
			//stream << res;
			//stream >> num_as_string;
			//std::cout << "Pushing back : " << res << std::endl;
			new_vec.push_back(std::to_string(res));
		}

	}
	//print_vector(new_vec);
	return (new_vec);

}

