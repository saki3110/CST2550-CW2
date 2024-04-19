#ifndef RENTAL_H
#define RENTAL_H

#include <ctime>
#include <string>

class Rental {
private:
    int id; // Unique identifier for the rental
    int movieId; // Identifier of the rented movie
    int customerId; // Identifier of the customer who rented the movie
    std::time_t rentalDate; // Date when the rental was made
    std::time_t dueDate; // Date when the rented movie is due to be returned
    std::time_t returnDate; // Date when the rented movie was returned
    double rentalFee; // Fee charged for the rental

public:
    Rental(int id, int movieId, int customerId, const std::time_t& rentalDate, const std::time_t& dueDate, double rentalFee);
    int getId() const;
    int getMovieId() const;
    int getCustomerId() const;
    std::time_t getRentalDate() const;
    std::time_t getDueDate() const;
    std::time_t getReturnDate() const;
    double getRentalFee() const;
    double calculateLateFee(const std::time_t& returnDate) const;
    void setReturnDate(const std::time_t& returnDate);
};

#endif
