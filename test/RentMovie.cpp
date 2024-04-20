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

// Test function to test renting a movie
TEST_CASE("RentMovie") {
    // Create a movie
    Movie movie(1, "The Shawshank Redemption", "Drama", 142, 1994, 9.3);

    // Create a customer
    Customer customer(1, "Sakina", "123 Main St", "123-456-7890","sakina34@gmail.com");

    // Create a rental
    std::time_t rentalDate = std::time(0);
    std::time_t dueDate = rentalDate + 7 * 24 * 60 * 60; // 7 days later
    Rental rental(1, movie.getId(), customer.getId(), rentalDate, dueDate, 2.5);

    // Check if the rental details are correct
    REQUIRE(rental.getId() == 1);
    REQUIRE(rental.getMovieId() == movie.getId());
    REQUIRE(rental.getCustomerId() == customer.getId());
    REQUIRE(rental.getRentalDate() == rentalDate);
    REQUIRE(rental.getDueDate() == dueDate);
    REQUIRE(rental.getReturnDate() == 0);
    REQUIRE(rental.getRentalFee() == 2.5);
}
