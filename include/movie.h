#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <unordered_set>

class Movie {
private:
    int id;
    std::string title;
    std::string genre;
    int releaseYear;
    double rentalFee;
    bool availability;

public:
    Movie(int id, const std::string& title, const std::string& genre, int releaseYear, double rentalFee);
    static std::vector<Movie> readMoviesFromCSV(const std::string& filename);
    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getReleaseYear() const;
    double getRentalFee() const;
    bool isAvailable() const;
    void setAvailability(bool available);
};

void displayMovies(const std::vector<Movie>& movies);
void displayMoviesByGenre(const std::vector<Movie>& movies, const std::string& genre);
void displayAllGenres(const std::vector<Movie>& movies);
void displayMoviesWithID(const std::vector<Movie>& movies, int id);
void displayMoviesWithPriceSort(const std::vector<Movie>& movies);
int binarySearch(const std::vector<Movie>& movies, int id, int low, int high);

#endif
