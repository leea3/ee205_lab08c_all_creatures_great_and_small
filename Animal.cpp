///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Animal.h"

using namespace std;

const string Animal::kingdom = "Animalia";

Animal::Animal(const string &newSpecies) : species(newSpecies) {
    setSpecies( newSpecies );
}

Animal::Animal(const string &newSpecies, Gender gender) : species(newSpecies), gender(gender) {
    setSpecies( newSpecies );
}

Animal::Animal(const string &newSpecies, Gender gender, float newWeight) : species(newSpecies), gender(gender), weight(newWeight) {
    setSpecies( newSpecies );
    setWeight( newWeight );
}

Animal::Animal(const string &newSpecies, float newWeight) : species(newSpecies), weight(newWeight) {
    setSpecies( newSpecies );
    setWeight( newWeight );
}

const string &Animal::getKingdom() {
    return kingdom;
}

const string &Animal::getSpecies() const {
    return species;
}

Gender Animal::getGender() const {
    return gender;
}

void Animal::setGender(Gender newGender) {
    if( gender != UNKNOWN_GENDER && newGender != UNKNOWN_GENDER )
        throw logic_error( "Previous Gender must be UNKNOWN_GENDER" );

    Animal::gender = newGender;

}

float Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(float newWeight) {
    if( !isValidWeight( newWeight ) ){
        throw invalid_argument( "Weight must be > 0" );
    }
    Animal::weight = newWeight;
}

void Animal::printInfo() {
    cout << "Animal Fields" << endl;
    cout << "Kingdom = [" << getKingdom() << "]" << endl;
    cout << "Species = [" << getSpecies() << "]" << endl;
    cout << "Weight =  [" << getWeight() << "]" << endl;
    cout << "Gender =  [" << getGender() << "]" << endl;
}

bool Animal::isValid() {
    if( !isValidWeight( weight ) )
        return false;

    return true;
}

bool Animal::isValidWeight(const float checkWeight) {
    if( checkWeight == UNKNOWN_WEIGHT )
        return false;

    if( checkWeight > 0 )
        return true;

    return false; //invalid for all other cases
}

bool Animal::isValidSpecies(const std::string checkSpecies) {
    if( checkSpecies.empty() )
        return false;

    return true;
}

void Animal::setSpecies(const std::string newSpecies) {
    if( !isValidSpecies( newSpecies ) )
        throw invalid_argument( "A species cannot be empty." );

    species = newSpecies;

}
