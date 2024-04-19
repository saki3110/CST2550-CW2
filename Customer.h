//
// Created by SAKINA on 19/04/2024.
//

#ifndef CST2550_CW2_CUSTOMER_H
#define CST2550_CW2_CUSTOMER_H

// Include necessary libraries
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>

// Define the Customer class
class Customer {
private: // Private attributes
    int id; // Customer's ID
    std::string name; // Customer's name
    std::string address; // Customer's address
    std::string phoneNumber; // Customer's phone number
    std::string email; // Customer's email
    std::string membershipStatus; // Customer's membership status

public: // Public methods
    Customer(int id, const std::string& name, const std::string& address, const std::string& phoneNumber, const std::string& email); // Constructor
    int getId() const;  // Getter for ID
    std::string getName() const; // Getter for name
    std::string getAddress() const; // Getter for address
    std::string getPhoneNumber() const; // Getter for phone number
    std::string getEmail() const; // Getter for email
    std::string getMembershipStatus() const; // Getter for membership status
    void updateMembershipStatus(const std::string& newStatus); // Method to update membership status
};

// Function declarations
void displayAllCustomers(const std::vector<Customer>& customers); // Display all customers
void displayCustomerWithID(const std::vector<Customer>& customers, int id); // Display a customer with a specific ID
void displayCustomerWithName(const std::vector<Customer>& customers, const std::string& name); // Display a customer with a specific name
void addNewCustomer(std::vector<Customer>& customers); // Add a new customer
void updateMembershipStatus(std::vector<Customer>& customers); // Update the membership status of a customer
void displayAllRegularCustomers(const std::vector<Customer>& customers);  // Display all regular customers
void displayAllPremiumCustomers(const std::vector<Customer>& customers); // Display all premium customers

#endif //CST2550_CW2_CUSTOMER_H
// End of the conditional directive
