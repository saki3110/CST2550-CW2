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
    return id;
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

// Function to display movies from a given array of movies
void displayMovies(const std::vector<Movie>& movies) {
    std::cout << "Movies:\n";

    // Loop through the array
    for (const auto& movie : movies) {

        // Print the movie neatly with formatting to seperate movies appropriately
        std::cout << "ID: " << movie.getId() << "\nTitle: " << movie.getTitle() << "\nGenre: " << movie.getGenre()
                  << "\nRelease Year: " << movie.getReleaseYear() << "\nRental Fee: $" << movie.getRentalFee()
                  << "\nAvailability: " << (movie.isAvailable() ? "Available" : "Not Available") 
                  << "\n-----------------------------------\n";
    }
}

// Function to display movies by genre, using a given array of movies and a given genre
void displayMoviesByGenre(const std::vector<Movie>& movies, const std::string& genre) {
    std::cout << "Movies in " << genre << " genre:\n";

    // Loop through the movies and identify the movies with the given genre
    for (const auto& movie : movies) {
        if (movie.getGenre() == genre) {

            // Print the movie neatly with formatting to seperate movies appropriately
            std::cout << "ID: " << movie.getId() << "\nTitle: " << movie.getTitle() << "\nGenre: " << movie.getGenre()
                  << "\nRelease Year: " << movie.getReleaseYear() << "\nRental Fee: $" << movie.getRentalFee()
                  << "\nAvailability: " << (movie.isAvailable() ? "Available" : "Not Available") 
                  << "\n--------------------------------\n";
        }
    }
    // Check the movies array and make use of a Lambda function to ensure that the given genre exits
    if (std::find_if(movies.begin(), movies.end(), [genre](const Movie& movie) { return movie.getGenre() == genre; }) == movies.end()) {
        std::cout << "No movies found in this genre.\n";
    }
}

// Function to display all of the movie genres available
void displayAllGenres(const std::vector<Movie>& movies) {

    // Make use of a set to make sure all genres are unique
    std::unordered_set<std::string> uniqueGenres;

    // Loop through all the movies and add their genres to the set
    for (const auto& movie : movies) {
        uniqueGenres.insert(movie.getGenre());
    }

    // Print out all the genres by looping through them
    std::cout << "Available Genres:\n";
    for (const auto& genre : uniqueGenres) {
        std::cout << "- " << genre << '\n';
    }
}

// Binary Search function to get a movie using a given ID and sorted array of movies
int binarySearch(const std::vector<Movie>& movies, int id, int low, int high) {

    // In the case that the list is exhausted, the ID is not found. Return -1 for interpretation.
    if (low > high) {
        return -1;
    }

    // Calculate the middle index
    int mid = low + (high - low) / 2; 

    // Check if the middle movie's ID matches the given ID
    if (movies[mid].getId() == id) {
        return mid;                                         // ID found at the middle index
    }
    else if (movies[mid].getId() < id) {
        return binarySearch(movies, id, mid + 1, high);     // Search in the right half of the array
    }
    else {
        return binarySearch(movies, id, low, mid - 1);      // Search in the left half of the array
    }
}

// Function to display a movie with a given ID
void displayMoviesWithID(const std::vector<Movie>& movies, int id){

    // Get the index of the requested movie using binary search
    int movieIndex = binarySearch(movies, id, 0, movies.size() - 1);

    // Display the movie if its ID was found
    if (movieIndex != -1) {
        // Get the required movie from the array
        const Movie& movie = movies[movieIndex];

        // Print the details
        std::cout << "\nID: " << movie.getId() << "\nTitle: " << movie.getTitle() << "\nGenre: " << movie.getGenre()
                  << "\nRelease Year: " << movie.getReleaseYear() << "\nRental Fee: $" << movie.getRentalFee();
    }

    // Print an error if no movie was found with the given ID
    else {
        std::cout << "No movie found with this ID.\n";
    }
}

// Function to display movies, sorted by price
void displayMoviesWithPriceSort(const std::vector<Movie>& movies) {

    // Sorted movies vector array for display
    std::vector<Movie> sortedMovies = movies;

    // Sort the given movies vector array
    std::sort(sortedMovies.begin(), sortedMovies.end(), [](const Movie& a, const Movie& b) {
        return a.getRentalFee() < b.getRentalFee();
    });

    // Print the sorted array by looping through it
    std::cout << "Movies sorted by price:\n";
    for (const auto& movie : sortedMovies) {
        std::cout << "\nID: " << movie.getId() << "\nTitle: " << movie.getTitle()
                  << "\nRental Fee: $" << movie.getRentalFee() 
                  << "\n-----------------------------------\n";
    }
}