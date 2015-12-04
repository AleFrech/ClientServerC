//
// Created by alejandrofrech on 11-27-15.
//
#include "User.h"

string User::to_s() {
    return this->Username+","+this->Name+","+this->Email+","+this->Cedula+","+this->Date+","+this->ImgUrl;
}