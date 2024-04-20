//
// Created by SAKINA on 19/04/2024.
//

#include "Customer.h"

// Define a constructor for the Customer class
Customer::Customer(int id, const std::string& name, const std::string& address, const std::string& phoneNumber, const std::string& email)
        : id(id), name(name), address(address), phoneNumber(phoneNumber), email(email), membershipStatus("Regular") {}

// Define getter methods for the Customer class
int Customer::getId() const {
    return id; // Return the customer's ID
}

std::string Customer::getName() const {
    return name; // Return the customer's name
}

std::string Customer::getAddress() const {
    return address; // Return the customer's address
}++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

std::string Customer::getPhoneNumber() const {
    return phoneNumber; // Return the customer's phone number
}
}

std::string Customer::getEmail() const {
    return email; // Return the customer's email
}

std::string Customer::getMembershipStatus() const {
    return membershipStatus; // Return the customer's membership status
}

oid Customer::updateMembershipStatus(const std::string& newStatus) {
    membershipStatus = newStatus; // Update the membership status
}

// Define a function to display all customers
void displayAllCustomers(const std::vector<Customer>& customers) {
    std::cout << "Customers:\n\n";
    for (const auto& customer : customers) {
        std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                  << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                  << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
                      // Print each customer's details
    }
}

// Define a function to display a customer with a specific ID
void displayCustomerWithID(const std::vector<Customer>& customers, int id) {
    for (const auto& customer : customers) {
        if (customer.getId() == id) { // Print the customer's details if the ID matches
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [id](const Customer& customer) { return customer.getId() == id; }) == customers.end()) {
        std::cout << "No customer found with this ID.\n";
    }
}

// Define a function to display a customer with a specific name
void displayCustomerWithName(const std::vector<Customer>& customers, const std::string& name) {
    for (const auto& customer : customers) {
        if (customer.getName() == name) { // Print the customer's details if the name matches
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    // Print a message if no customer was found with the given name
    if (std::find_if(customers.begin(), customers.end(), [name](const Customer& customer) { return customer.getName() == name; }) == customers.end()) {
        std::cout << "No customer found with this name.\n";
    }
}

// Define a function to add a new customer
void addNewCustomer(std::vector<Customer>& customers) {
    // The new customer's ID is one more than the current number of customers
    int id = customers.size() + 1;
    std::string name, address, phoneNumber, email;
    char membershipOption;

    // Prompt the user to enter the new customer's details
    std::cout << "Enter customer name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);
    std::cout << "Enter customer phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter customer email: ";
    std::cin >> email;

    // Prompt for membership status
    std::cout << "Select membership status:\n";
    std::cout << "1. Regular\n";
    std::cout << "2. Premium\n";
    std::cout << "Enter option: ";
    std::cin >> membershipOption;

    std::string membershipStatus;
    switch (membershipOption) {
        case '1':
            membershipStatus = "Regular";
            break;
        case '2':
            membershipStatus = "Premium";
            break;
        default:
            std::cerr << "Invalid option. Defaulting to Regular membership.\n";
            membershipStatus = "Regular";
            break;
    }

    // Add the new customer to the list of customers
    customers.push_back(Customer(id, name, address, phoneNumber, email));
    customers.back().updateMembershipStatus(membershipStatus);
    std::cout << "Customer added successfully.\n";
}

// Define a function to update the membership status of a customer
void updateMembershipStatus(std::vector<Customer>& customers) {
    int id; // Variable to store the customer's ID
    char membershipOption; // Variable to store the membership option

    std::cout << "Enter customer ID: "; // Prompt the user to enter the customer's ID
    std::cin >> id; // Read the customer's ID

    // Find the customer with the given ID
    auto it = std::find_if(customers.begin(), customers.end(), [id](const Customer& customer) { return customer.getId() == id; });
    if (it != customers.end()) { // If the customer is found
        std::cout << "Select membership status:\n"; // Prompt the user to select the membership status
        std::cout << "1. Regular\n";
        std::cout << "2. Premium\n";
        std::cout << "Enter option: ";
        std::cin >> membershipOption; // Read the membership option

        std::string membershipStatus; // Variable to store the membership status
        switch (membershipOption) { // Update the membership status based on the selected option
            case '1':
                membershipStatus = "Regular";
                break;
            case '2':
                membershipStatus = "Premium";
                break;
            default:
                std::cerr << "Invalid option. Defaulting to Regular membership.\n";
                membershipStatus = "Regular";
                break;
        }

        it->updateMembershipStatus(membershipStatus); // Update the membership status of the customer
        std::cout << "Membership status updated successfully.\n"; // Print a success message
    } else {
        std::cout << "No customer found with this ID.\n"; // Print a message if no customer was found with the given ID
    }
}

// Define a function to display all regular customers
void displayAllRegularCustomers(const std::vector<Customer>& customers) { // For each customer in the customers vector
    std::cout << "Regular Customers:\n\n";
    for (const auto& customer : customers) { // For each customer in the customers vector
        if (customer.getMembershipStatus() == "Regular") { // For each customer in the customers vector
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [](const Customer& customer) { return customer.getMembershipStatus() == "Regular"; }) == customers.end()) {
        std::cout << "No regular customers found.\n";  // Print a message if no regular customers were found
    }
}

// Define a function to display all premium customers
void displayAllPremiumCustomers(const std::vector<Customer>& customers) {
    std::cout << "Premium Customers:\n\n";
    for (const auto& customer : customers) {
        if (customer.getMembershipStatus() == "Premium") { // If the customer is a premium customer
            // Print the customer's details
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [](const Customer& customer) { return customer.getMembershipStatus() == "Premium"; }) == customers.end()) {
        std::cout << "No premium customers found.\n"; // Print a message if no premium customers were found
    }
    }
}





