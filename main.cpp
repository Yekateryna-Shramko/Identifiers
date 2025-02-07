#include <iostream>

#include "runway.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        throw std::runtime_error("Usage: ./runwaybin.exe <runway_identifier>");
    }
    std::cout << runway::transform_runway_identifier_to_opposite_direction(std::string{argv[1]});
}
