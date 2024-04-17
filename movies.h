//
// Created by SAKINA on 17/04/2024.git@github.com:saki3110/CST2550-CW2.git
//

#include <string>
#include <vector>

class Video {
public:
    std::string title;
    bool is_rented;
    double fees;
};

class Client {
public:
    std::string name;
    std::vector<Video> rented_videos;
};

class Staff {
public:
    std::string name;
};

class VideoStore {
private:
    std::vector<Video> videos;
    std::vector<Client> clients;
    std::vector<Staff> staffs;
public:
    void add_video(const std::string& title);
    void delete_video(const std::string& title);
    void search_video(const std::string& title);
    void rent_video(Client& client, const std::string& title);
    double calculate_fees(const Client& client);
    void return_video(Client& client, const std::string& title);
    double calculate_overdue_fees(const Client& client);
};

