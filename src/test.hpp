#include <iostream>
#include <fstream>
#include <chrono>
#include <assert.h>

#include "city.hpp"
#include "database.hpp"

using namespace std::chrono;
#define FILE_NAME "cities.txt"

data_base<city, std::string> *push_from_file(std::ifstream& file);
double clock_item(const std::string& name, data_base<city, std::string> *database);

void test_cache_time_0();
void test_cache_time_1();
void test_cache_time_2();
void test_cache_time_3();
void test_cache_time_4();
void test_cache_time_5();

void test() {
    test_cache_time_0();
    test_cache_time_1();
    test_cache_time_2();
    test_cache_time_3();
    test_cache_time_4();
    test_cache_time_5();

    std::cout << "Tests passed" << std::endl;
}

void test_cache_time_0() {
        std::ifstream file(FILE_NAME);

    if (file.is_open()) {
        auto database = push_from_file(file);

        double first_time = clock_item("Addison", database);
        double second_time = clock_item("Addison", database);

        assert(second_time * 10 < first_time);
        delete database;
    }

    file.close();
}

void test_cache_time_1() {
    std::ifstream file(FILE_NAME);

    if (file.is_open()) {
        auto database = push_from_file(file);

        double first_time = clock_item("Addison", database);
    
        database->get_item("Phenix City");
        database->get_item("San Bruno");
        database->get_item("Bell Gardens");
        database->get_item("Rancho Palos Verdes");
        database->get_item("Apex");
        database->get_item("Manassas");
        database->get_item("Minot");
        database->get_item("Euclid");
        database->get_item("La Mirada");
        database->get_item("Saginaw");
        database->get_item("Huntersville");
        database->get_item("Palm Desert");
        database->get_item("Cutler Bay");
        database->get_item("Wylie");
        database->get_item("Pine Bluff");
        database->get_item("Azusa");
        database->get_item("Monroe");
        database->get_item("Covina");
        database->get_item("Parker"); // 20
        database->get_item("Covina"); // already in cache

        double second_time = clock_item("Addison", database);

        assert(second_time * 10 < first_time);
        delete database;
    }

    file.close();
}

void test_cache_time_2() {
        std::ifstream file(FILE_NAME);

    if (file.is_open()) {
        auto database = push_from_file(file);

        double first_time = clock_item("Addison", database);

        database->get_item("Phenix City");
        database->get_item("San Bruno");
        database->get_item("Bell Gardens");
        database->get_item("Rancho Palos Verdes");
        database->get_item("Apex");
        database->get_item("Manassas");
        database->get_item("Minot");
        database->get_item("Euclid");
        database->get_item("La Mirada");
        database->get_item("Saginaw");
        database->get_item("Huntersville");
        database->get_item("Palm Desert");
        database->get_item("Cutler Bay");
        database->get_item("Wylie");
        database->get_item("Pine Bluff");
        database->get_item("Azusa");
        database->get_item("Monroe");
        database->get_item("Covina");
        database->get_item("Parker"); // 20
        database->get_item("Belleville"); // 21

        double second_time = clock_item("Addison", database);

        assert(abs(first_time - second_time) < 1E-4);
        delete database;
    }

    file.close();
}

void test_cache_time_3() {
        std::ifstream file(FILE_NAME);

    if (file.is_open()) {
        auto database = push_from_file(file);

        database->get_item("Phenix City");
        database->get_item("San Bruno");
        database->get_item("Bell Gardens");
        database->get_item("Rancho Palos Verdes");
        database->get_item("Apex");

        double first_time = clock_item("Addison", database);

        database->get_item("Manassas");
        database->get_item("Minot");
        database->get_item("Euclid");
        database->get_item("La Mirada");
        database->get_item("Saginaw");
        database->get_item("Huntersville");
        database->get_item("Palm Desert");
        database->get_item("Cutler Bay");
        database->get_item("Wylie");
        database->get_item("Pine Bluff");
        database->get_item("Azusa");
        database->get_item("Monroe");
        database->get_item("Covina");
        database->get_item("Parker"); // 20

        double second_time = clock_item("Addison", database);

        assert(second_time * 10 < first_time);
        delete database;
    }

    file.close();
}

void test_cache_time_4() {
        std::ifstream file(FILE_NAME);

    if (file.is_open()) {
        auto database = push_from_file(file);

        database->get_item("Phenix City");
        database->get_item("San Bruno");
        database->get_item("Bell Gardens");
        database->get_item("Rancho Palos Verdes");
        database->get_item("Apex");
        database->get_item("Manassas");
        database->get_item("Minot");
        database->get_item("Euclid");
        database->get_item("La Mirada");
        database->get_item("Saginaw");
        database->get_item("Huntersville");
        database->get_item("Palm Desert");
        database->get_item("Cutler Bay");
        database->get_item("Wylie");
        database->get_item("Pine Bluff");
        database->get_item("Azusa");
        database->get_item("Monroe");
        database->get_item("Covina");
        database->get_item("Parker");
        double first_time = clock_item("Addison", database); // 20
        double second_time = clock_item("Addison", database);

        assert(second_time * 10 < first_time);
        delete database;
    }

    file.close();
}

void test_cache_time_5() {
        std::ifstream file(FILE_NAME);

    if (file.is_open()) {
        auto database = push_from_file(file);

        database->get_item("Phenix City");
        database->get_item("San Bruno");
        database->get_item("Bell Gardens");
        database->get_item("Rancho Palos Verdes");
        database->get_item("Apex");
        database->get_item("Manassas");
        database->get_item("Minot");
        database->get_item("Euclid");
        database->get_item("La Mirada");
        database->get_item("Saginaw");
        database->get_item("Huntersville");
        database->get_item("Palm Desert");
        database->get_item("Cutler Bay");
        database->get_item("Wylie");
        database->get_item("Pine Bluff");
        database->get_item("Azusa");
        database->get_item("Monroe");
        database->get_item("Covina");
        database->get_item("Parker");
        database->get_item("Columbus"); // 20
        double first_time = clock_item("Addison", database); // 21
        double second_time = clock_item("Addison", database);

        assert(second_time * 10 < first_time);
        delete database;
    }

    file.close();
}

data_base<city, std::string> *push_from_file(std::ifstream& file) {
    auto database = new data_base<city, std::string>();
    std::string city_name;
    std::size_t population;

    std::string buffer;
    while (!file.eof()) {
        std::getline(file, buffer, ',');
        std::getline(file, city_name, ',');
        std::getline(file, buffer, ',');
        file >> population;
        std::getline(file, buffer, ',');
        std::getline(file, buffer, '\n');

        city *data = new city(city_name, population);
        bool status = database->push_item(data);
    
        if (status) delete data;
    }

    return database;
}

double clock_item(const std::string& name, data_base<city, std::string> *database) {
    auto start_clock = high_resolution_clock::now();
    city *item = database->get_item(name);
    auto stop_clock = high_resolution_clock::now();
    duration<double> duration = stop_clock - start_clock;

    return duration.count();
}