#include "Customer.h"

// Customer class implementation
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
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

std::string Customer::getEmail() const {
    return email;
}

std::string Customer::getMembershipStatus() const {
    return membershipStatus;
}

void Customer::updateMembershipStatus(const std::string& newStatus) {
    membershipStatus = newStatus;
}

//function to display all customers
void displayAllCustomers(const std::vector<Customer>& customers) {
    std::cout << "Customers:\n\n";
    for (const auto& customer : customers) {
        std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                  << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                  << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
    }
}

//function to display customer with ID
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

//function to display customer with name
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

//function to add new customer
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
    // Add new customer to the vector
    customers.push_back(Customer(id, name, address, phoneNumber, email));
    customers.back().updateMembershipStatus(membershipStatus);
    std::cout << "Customer added successfully.\n";
}

//function to update membership status
void updateMembershipStatus(std::vector<Customer>& customers) {
    int id;
    char membershipOption;

    std::cout << "Enter customer ID: ";
    std::cin >> id;
    //find customer with ID
    auto it = std::find_if(customers.begin(), customers.end(), [id](const Customer& customer) { return customer.getId() == id; });
    if (it != customers.end()) {
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
        // Update membership status
        it->updateMembershipStatus(membershipStatus);
        std::cout << "Membership status updated successfully.\n";
    } else {
        std::cout << "No customer found with this ID.\n";
    }
}

//display all regular customers
void displayAllRegularCustomers(const std::vector<Customer>& customers) {
    std::cout << "Regular Customers:\n\n";
    for (const auto& customer : customers) {
        if (customer.getMembershipStatus() == "Regular") {
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [](const Customer& customer) { return customer.getMembershipStatus() == "Regular"; }) == customers.end()) {
        std::cout << "No regular customers found.\n";
    }
}

//display all premium customers
void displayAllPremiumCustomers(const std::vector<Customer>& customers) {
    std::cout << "Premium Customers:\n\n";
    for (const auto& customer : customers) {
        if (customer.getMembershipStatus() == "Premium") {
            std::cout << "ID: " << customer.getId() << "\nName: " << customer.getName() << "\nAddress: " << customer.getAddress()
                      << "\nPhone Number: " << customer.getPhoneNumber() << "\nEmail: " << customer.getEmail()
                      << "\nMembership Status: " << customer.getMembershipStatus() << "\n\n";
        }
    }
    if (std::find_if(customers.begin(), customers.end(), [](const Customer& customer) { return customer.getMembershipStatus() == "Premium"; }) == customers.end()) {
        std::cout << "No premium customers found.\n";
    }
}