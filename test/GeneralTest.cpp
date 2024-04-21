#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Rental.h"
#include "Movie.h"
#include "Customer.h"


// Define binarySearch function
int binarySearch(const std::vector<Movie>& movies, int id, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (movies[mid].getId() == id)
            return mid;
        else if (movies[mid].getId() < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

TEST_CASE("Movie initialization", "[Movie]") {
    Movie movie(1, "Test Title", "Test Genre", 2000, 10.0);

    REQUIRE(movie.getId() == 1);
    REQUIRE(movie.getTitle() == "Test Title");
    REQUIRE(movie.getGenre() == "Test Genre");
    REQUIRE(movie.getReleaseYear() == 2000);
    REQUIRE(movie.getRentalFee() == 10.0);
    REQUIRE(movie.isAvailable() == true);
}


TEST_CASE("Movie availability", "[Movie]") {
    Movie movie(1, "Test Title", "Test Genre", 2000, 10.0);

    movie.setAvailability(false);
    REQUIRE(movie.isAvailable() == false);

    movie.setAvailability(true);
    REQUIRE(movie.isAvailable() == true);
}

TEST_CASE("Movie read from CSV", "[Movie]") {
    std::vector<Movie> movies = Movie::readMoviesFromCSV("test.csv");

    REQUIRE(movies.size() > 0);
}

TEST_CASE("Binary Search", "[Movie]") {
    std::vector<Movie> movies = Movie::readMoviesFromCSV("test.csv");
    std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) { return a.getId() < b.getId(); });

    int id = movies[0].getId();
    int index = binarySearch(movies, id, 0, movies.size() - 1);

    REQUIRE(index != -1);
    REQUIRE(movies[index].getId() == id);
}
