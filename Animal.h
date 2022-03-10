///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

enum Gender {
    UNKNOWN_GENDER, MALE, FEMALE
};


class Animal {
protected:
    static const std::string kingdom;
    std::string              species;
    enum Gender              gender;
    float                    weight;

};