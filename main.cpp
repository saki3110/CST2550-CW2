#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include "Movie.h"
#include "Customer.h"
#include "Rental.h"

int main() {
    std::vector<Movie> movies = Movie::readMoviesFromCSV("movies.csv");

    std::vector<Customer> customers;
    //Sample customers
    customers.push_back(Customer(1, "Sakina", "123 Main St", "123-456-7890","sakina34@gmail.com"));
    customers.push_back(Customer(2, "Dristi Bhugun", "456 Elm St", "234-567-8901","dristi.db@gmail.com"));
    customers.push_back(Customer(3, "Adolf Hitler", "789 Oak St", "345-678-9012","adolf78@gmail.com"));
    customers.push_back(Customer(4, "Jason", "987 Pine St", "456-789-0123","jason7@gmail.com"));
    customers.push_back(Customer(5, "Yashvin", "654 Birch St", "567-890-1234","yash673@gmail.com"));

    std::vector<Rental> rentals;
    //Sample Rentals
    rentals.push_back(Rental(1, 1, 1, std::time(0), std::time(0), 2.99));
    rentals.push_back(Rental(2, 2, 2, std::time(0), std::time(0), 3.99));

    int choice;
    do {
        std::cout << "\n------Movie Rental System------\n";
        std::cout << "1. Display Movies\n"
                  << "2. Display Customers\n"
                  << "3. Rent a Movie\n"
                  << "4. Return a movie\n"
                  << "5. Exit\n"
                  << "-----------------------------";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                char subChoice;
                std::cout << "-----------------------------\n"
                          << "1. All Movies\n"
                          << "2. Movies by Genre\n"
                          << "3. Movies with Price sort\n"
                          << "4. Search movie with ID\n"
                          << "5. Exit\n"
                          << "-----------------------------";
                std::cout << "\nEnter your choice: ";
                std::cin >> subChoice;

                switch (subChoice) {
                    case '1': {
                        displayMovies(movies);
                        break;
                    }
                    case '2': {
                        displayAllGenres(movies);
                        std::string genre;
                        std::cout << "Enter genre: ";
                        std::cin >> genre;
                        displayMoviesByGenre(movies, genre);
                        break;
                    }
                    case '3': {
                        displayMoviesWithPriceSort(movies);
                        break;
                    }
                    case '4': {
                        int id;
                        std::cout << "Enter movie ID: ";
                        std::cin >> id;
                        displayMoviesWithID(movies, id);
                        break;
                    }
                    case '5': {
                        std::cout << "Exiting...\n";
                        break;
                    }
                    default: {
                        std::cout << "Invalid choice.\n";
                        break;
                    }
                }
                break;
            }






    return 0;
}
