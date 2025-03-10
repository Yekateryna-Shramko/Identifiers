#ifndef RUNWAY_H
#define RUNWAY_H
#include <string>

namespace runway {
    char transform_runway_suffix_to_opposite_direction(char suffix);

    std::string transform_number_to_opposite_direction(std::string_view number);

    std::string transform_runway_identifier_to_opposite_direction(std::string_view runway_identifier);
}

#endif //RUNWAY_H
