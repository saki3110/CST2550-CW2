#include <iostream>
#include <ctime>
#include <iomanip>
#include "Rental.h"


Rental::Rental(int id, int movieId, int customerId, const std::time_t& rentalDate, const std::time_t& dueDate, double rentalFee)
    : id(id), movieId(movieId), customerId(customerId), rentalDate(rentalDate), dueDate(dueDate), returnDate(0), rentalFee(rentalFee) {}

// Getter method for rental ID
int Rental::getId() const {
    return id;
}

// Getter method for movie ID
int Rental::getMovieId() const {
    return movieId;
}

// Getter method for customer ID
int Rental::getCustomerId() const {
    return customerId;
}

// Getter method for rental date
std::time_t Rental::getRentalDate() const {
    return rentalDate;
}

// Getter method for due date
std::time_t Rental::getDueDate() const {
    return dueDate;
}

// Getter method for return date
std::time_t Rental::getReturnDate() const {
    return returnDate;
}

// Getter method for rental fee
double Rental::getRentalFee() const {
    return rentalFee;
}

// Method to calculate late fee based on return date
double Rental::calculateLateFee(const std::time_t& returnDate) const {
    // Calculate the number of days overdue
    double daysOverdue = difftime(returnDate, dueDate) / (60 * 60 * 24);
    // Define late fee rate per day
    const double lateFeePerDay = 1.5; 
    // Calculate late fee
    double lateFee = daysOverdue * lateFeePerDay;
    // Ensure late fee is not negative
    return (lateFee > 0) ? lateFee : 0;
}
// Setter method for return date
void Rental::setReturnDate(const std::time_t& returnDate) {
    this->returnDate = returnDate;
}


