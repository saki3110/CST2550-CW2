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

// Test function to test renting a rented movie
TEST_CASE("RentARentedMovie") {
    // Create a movie
    Movie movie(1, "The Shawshank Redemption", "Drama", 142, 1994, 9.3);

    // Create a customer
    Customer customer(1, "Sakina", "123 Main St", "123-456-7890","sakina34@gmail.com");

    // Create the first rental
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
    
    // Rent the movie again
    Rental rental2(2, movie.getId(), customer.getId(), rentalDate, dueDate, 2.5);

    // Check if the rental details for the second rental are correct
    REQUIRE(rental2.getId() == 2);
    REQUIRE(rental2.getMovieId() == movie.getId());
    REQUIRE(rental2.getCustomerId() == customer.getId());
    REQUIRE(rental2.getRentalDate() == rentalDate);
    REQUIRE(rental2.getDueDate() == dueDate);
    REQUIRE(rental2.getReturnDate() == 0);
    REQUIRE(rental2.getRentalFee() == 2.5);
}
