#include "factors.h"
#include <iostream>
#include <fstream>
#include <cmath>

std::vector<std::pair<int, int>> factorize(int number) {
    std::vector<std::pair<int, int>> factors;
    for (int b = 2; b <= sqrt(number); ++b) {
        if (number % b == 0) {
	    factors.emplace_back(b, number / b);
        }
    }
    return factors;
}


void factorize_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "Failed to open the file: " << file_path << std::endl;
        return;
    }

    int number;
    while (file >> number) {
        std::vector<std::pair<int, int>> factors = factorize(number);
        for (const auto& factor : factors)
        {
            std::cout << number << " = " << factor.first << " * " << factor.second << std::endl;
        }
    }
}
