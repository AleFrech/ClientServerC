//
// Created by alejandrofrech on 11-27-15.
//

#ifndef CLIENTSERVERC_VALIDATIONS_H
#define CLIENTSERVERC_VALIDATIONS_H

#include "FileManager.h"
#include <iostream>
#include <string>
#include <regex>

class Validations {
public:
    FileManager *fm;
    Validations(){
        fm=new FileManager();
    }
    bool verifyEmail(string str);
    bool verifyCedula(string str);
    bool verifyDate(string str);
    bool verifyUser(string str);
};


#endif //CLIENTSERVERC_VALIDATIONS_H
