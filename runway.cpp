#include "runway.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace {
    void assertNumber(std::string_view str) {
        bool all_digits = !str.empty() && std::all_of(str.begin(), str.end(), [](char ch) {
            return std::isdigit(ch);
        });
        if (!all_digits) {
            throw std::runtime_error("Invalid runway number");
        }
    }
}

char runway::transform_runway_suffix_to_opposite_direction(char suffix) {
    switch (suffix) {
        case 'R':
            return 'L';
        case 'L':
            return 'R';
        case 'C':
            return 'C';
        default:
            throw std::runtime_error("Invalid runway suffix");
    }
}

std::string runway::transform_number_to_opposite_direction(std::string_view number) {
    assertNumber(number);
    int number_as_int = std::stoi(number.data());
    if (number_as_int <= 0 || number_as_int > 36) {
        throw std::runtime_error("Invalid runway number");
    }
    int opposite_number{(number_as_int + 18) % 36};
    if (opposite_number == 0) {
        opposite_number = 36;
    }

    if (opposite_number < 10) {
        return "0" + std::to_string(opposite_number);
    }
    return std::to_string(opposite_number);
}

std::string runway::transform_runway_identifier_to_opposite_direction(std::string_view runway_identifier) {
    if (runway_identifier.size() < 2 || runway_identifier.size() > 3) {
        throw std::runtime_error("Invalid runway identifier");
    }
    std::string opposite_number = transform_number_to_opposite_direction(runway_identifier.substr(0, 2));
    if (runway_identifier.size() == 3) {
        char opposite_direction = transform_runway_suffix_to_opposite_direction(runway_identifier.at(2));
        return opposite_number + opposite_direction;
    }
    return opposite_number;
}
