# Video Rental System

This coursework introduces a Video Rental System, a software application developed in C++. The system is designed to modernize the video rental industry by streamlining the process of renting movies to clients and efficiently managing pricing and overdue accounts. The system leverages a binary tree data structure, enabling staff to swiftly locate movies by their names, significantly reducing the time spent on inventory management. Furthermore, it offers the flexibility to manage the video inventory effectively by providing features to add new videos, ensuring the system stays current with the ever-changing movie landscape.


## Features

- Import Movies from a csv file
- Create new Customers
- Add or remove customer's plan
- Rent a movie to any customer for 7 days
- If user doesn't reutrn book after 7 days, user will be charged as $1.5 per day

## Commands

To make objects and executables
```sh
make
```

To run executable file
```sh
.\bin\VideoRentalSystem.exe
```

To clean project

```sh
make clean
```

## Testing

There are 2 unit tests 
- Rent a movie 
- Rent a rented movie 

```sh
cmake -S . -B build
```
```sh
cmake --build build 
```
Executable file will be in ./build

## Team

- Dristi Bhugun (M00846514)
- Sakina Taygaully (M00941082)
- Adolf Archibald (M00885478)
- Jason Bheekarry (M00909869)
- Nageswararao Balloo (M00865938)