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

// Method to read movies from a given CSV file. Returns a vector array of movies
std::vector<Movie> Movie::readMoviesFromCSV(const std::string& filename) {

    // Variable declerations
    std::vector<Movie> movies;
    std::ifstream file(filename);

    // Make sure the file is open
    if (!file.is_open()) {

        // Return empty vector array and log an error
        std::cerr << "Error opening file: " << filename << std::endl;
        return movies;
    }

    // Read all the lines from the file
    std::string line;
    while (std::getline(file, line)) {

        // Split each line into string variables
        std::istringstream iss(line);
        std::string id_str, title, genre, releaseYear_str, rentalFee_str;

        // Check that each line is correctly formatted and store the values in the variables
        if (std::getline(iss, id_str, ',') && std::getline(iss, title, ',') &&
            std::getline(iss, genre, ',') && std::getline(iss, releaseYear_str, ',') &&
            std::getline(iss, rentalFee_str)) {
            
            // Convert the variables to required format
            try {
                int id = std::stoi(id_str);
                int releaseYear = std::stoi(releaseYear_str);
                double rentalFee = std::stod(rentalFee_str);

                // Contruct a Movie object and push it into the vector array
                movies.emplace_back(id, title, genre, releaseYear, rentalFee);
            }

            // Log an error if there are any issues in the conversion process
            catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << std::endl;
            }
        }
        // Log an error if the line is incorrectly formatted
        else {
            std::cerr << "Invalid line format: " << line << std::endl;
        }
    }
    // Close the file and return the movies vector array
    file.close();
    return movies;
}