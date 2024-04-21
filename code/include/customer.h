#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>

class Customer {
private:
    int id;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::string membershipStatus;

public:
    Customer(int id, const std::string& name, const std::string& address, const std::string& phoneNumber, const std::string& email);
    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getMembershipStatus() const;
    void updateMembershipStatus(const std::string& newStatus);
};
void displayAllCustomers(const std::vector<Customer>& customers);
void displayCustomerWithID(const std::vector<Customer>& customers, int id);
void displayCustomerWithName(const std::vector<Customer>& customers, const std::string& name);
void addNewCustomer(std::vector<Customer>& customers);
void updateMembershipStatus(std::vector<Customer>& customers);
void displayAllRegularCustomers(const std::vector<Customer>& customers);
void displayAllPremiumCustomers(const std::vector<Customer>& customers);


#endif 
