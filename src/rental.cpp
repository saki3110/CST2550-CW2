#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Rental.h"

//Rental class implementation
Rental::Rental(int id, int movieId, int customerId, const std::time_t& rentalDate, const std::time_t& dueDate, double rentalFee)
    : id(id), movieId(movieId), customerId(customerId), rentalDate(rentalDate), dueDate(dueDate), returnDate(0), rentalFee(rentalFee) {}

int Rental::getId() const {
    return id;
}

int Rental::getMovieId() const {
    return movieId;
}

int Rental::getCustomerId() const {
    return customerId;
}

std::time_t Rental::getRentalDate() const {
    return rentalDate;
}

std::time_t Rental::getDueDate() const {
    return dueDate;
}

std::time_t Rental::getReturnDate() const {
    return returnDate;
}

double Rental::getRentalFee() const {
    return rentalFee;
}

//Caaclulate late fee
double Rental::calculateLateFee(const std::time_t& returnDate) const {
    double daysOverdue = difftime(returnDate, dueDate) / (60 * 60 * 24);

    const double lateFeePerDay = 1.5; 
    double lateFee = daysOverdue * lateFeePerDay;

    return (lateFee > 0) ? lateFee : 0;
}

//function to set return date
void Rental::setReturnDate(const std::time_t& returnDate) {
    this->returnDate = returnDate;
}

//function to return a movie
void returnMovie(std::vector<Rental>& rentals, int rentalId) {
    // Find the rental with the given ID
    auto rentalIt = std::find_if(rentals.begin(), rentals.end(), [rentalId](const Rental& rental) {
        return rental.getId() == rentalId;
    });

    if (rentalIt == rentals.end()) {
        std::cout << "Rental not found.\n";
        return;
    }

    // Get the current date
    std::time_t returnDate = std::time(0);

    // Update the return date
    rentalIt->setReturnDate(returnDate);

    // Remove the rental from the vector
    rentals.erase(rentalIt);

    std::cout << "Movie returned successfully.\n";
}
