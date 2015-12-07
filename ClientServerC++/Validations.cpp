//
// Created by alejandrofrech on 11-27-15.
//

#include "Validations.h"
bool Validations::verifyUser(string str) {

    if(fm->isUnique(str,0))
        return true;
    printf("%s\n","Username not valid or taken!!!");
    return false;
}
bool Validations::verifyEmail(string str) {
    if(fm->isUnique(str,2) && regex_match(str,std::regex("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}")))
        return true;
    printf("%s\n","Email not valid or taken!!!");
    return false;
}
bool Validations::verifyCedula(string str) {
    if(fm->isUnique(str,3) && std::regex_match (str, std::regex("\\d{4}-\\d{4}-\\d{5}")))
        return true;
    printf("%s\n","Id Number not valid !!!");
    return false;
}
bool Validations::verifyDate(string str) {
    if(std::regex_match (str, std::regex("\\d{2}-\\d{2}-\\d{4}")))
        return true;
    printf("%s\n","Date not valid !!!");
    return false;
}
