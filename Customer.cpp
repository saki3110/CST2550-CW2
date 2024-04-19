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
