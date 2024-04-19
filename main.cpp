#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include "Movie.h"
#include "Customer.h"
#include "Rental.h"

int main() {
    std::vector<Movie> movies = Movie::readMoviesFromCSV("movies.csv");

    std::vector<Customer> customers;



    return 0;
}
