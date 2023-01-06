#ifndef SRC_CITY_HPP_
#define SRC_CITY_HPP_

#include <string>

class city {
public:
    void print() {
        std::cout << this->data << " " << this->population << std::endl;
    }

public:
    city(std::string name, std::size_t population) :
    data(name),
    hash(std::hash<std::string>{}(name)),
    population(population) {}

public:
    std::string data;
    std::size_t population;
    std::size_t hash;
};

#endif  // SRC_CITY_HPP_