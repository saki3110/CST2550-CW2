#ifndef RENTAL_H
#define RENTAL_H

#include <ctime>
#include <string>

class Rental {
private:
    int id;
    int movieId;
    int customerId;
    std::time_t rentalDate;
    std::time_t dueDate;
    std::time_t returnDate;
    double rentalFee;

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
void returnMovie(std::vector<Rental>& rentals, int rentalId);

#endif
