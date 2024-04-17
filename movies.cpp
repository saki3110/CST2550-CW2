//
// Created by SAKINA on 17/04/2024.
//
#include "movies.h"

void VideoStore::add_video(const std::string& title) {
    // Add a new video to the store
}

void VideoStore::delete_video(const std::string& title) {
    // Delete a video from the store
}

Void VideoStore::search_video(const std::string& title) {
    // Search for a video in the store
}

void VideoStore::rent_video(Client& client, const std::string& title) {
    // Rent a video to a client
}

double VideoStore::calculate_fees(const Client& client) {
    // Calculate the total fees for a client
}

void VideoStore::return_video(Client& client, const std::string& title) {
    // Return a video from a client
}

double VideoStore::calculate_overdue_fees(const Client& client) {
    // Calculate the overdue fees for a client
}