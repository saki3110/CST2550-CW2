#include "movie.h"

// Movie initialisation
Movie::Movie(int id, const std::string& title, const std::string& genre, int releaseYear, double rentalFee) {
    this->id = id;
    this->title = title;
    this->genre = genre;
    this->releaseYear = releaseYear;
    this->rentalFee = rentalFee;
    this->availability = true;          // Default availability to true when instantiating
}

// Getter for ID
int Movie::getId() const {
}

// Getter for title
std::string Movie::getTitle() const {
    return title;
}

// Getter for genre
std::string Movie::getGenre() const {
    return genre;
}

// Getter for release year
int Movie::getReleaseYear() const {
    return releaseYear;
}

// Getter for rental fee
double Movie::getRentalFee() const {
    return rentalFee;
}

// Getter to check availability
bool Movie::isAvailable() const {
    return availability;
}

// Setter to set availability
void Movie::setAvailability(bool available) {
    availability = available;
}