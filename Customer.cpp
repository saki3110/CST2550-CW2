//
// Created by SAKINA on 19/04/2024.
//

#include "Customer.h"

Customer::Customer(int id, const std::string& name, const std::string& address, const std::string& phoneNumber, const std::string& email)
        : id(id), name(name), address(address), phoneNumber(phoneNumber), email(email), membershipStatus("Regular") {}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getAddress() const {
    return address;
}++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

std::string Customer::getEmail() const {
    return email;
}

std::string Customer::getMembershipStatus() const {
    return membershipStatus;
}

oid Customer::updateMembershipStatus(const std::string& newStatus) {
    membershipStatus = newStatus;
}

void displayAllCustomers(const std::vector<Customer>& customers) {
    std::cout << "Customers:\n\n";
    for (const auto& customer : customers) {
        std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                  << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                  << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
    }
}

void displayCustomerWithID(const std::vector<Customer>& customers, int id) {
    for (const auto& customer : customers) {
        if (customer.getId() == id) {
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [id](const Customer& customer) { return customer.getId() == id; }) == customers.end()) {
        std::cout << "No customer found with this ID.\n";
    }
}

void displayCustomerWithName(const std::vector<Customer>& customers, const std::string& name) {
    for (const auto& customer : customers) {
        if (customer.getName() == name) {
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [name](const Customer& customer) { return customer.getName() == name; }) == customers.end()) {
        std::cout << "No customer found with this name.\n";
    }
}

void addNewCustomer(std::vector<Customer>& customers) {
    int id = customers.size() + 1;
    std::string name, address, phoneNumber, email;
    char membershipOption;

    std::cout << "Enter customer name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);
    std::cout << "Enter customer phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter customer email: ";
    std::cin >> email;

}

