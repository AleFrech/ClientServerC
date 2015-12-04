//
// Created by alejandrofrech on 11-27-15.
//

#ifndef CLIENTSERVERC_FILEMANAGER_H
#define CLIENTSERVERC_FILEMANAGER_H
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class FileManager {

public:
    FileManager(){

    }
    bool writeUser(string user){
        ofstream file;
        file.open ("/home/alejandrofrech/ClionProjects/ClientServerC++/Data.txt",ios::in);
        if(file.end!=file.beg){
           file.close();
            file.open ("/home/alejandrofrech/ClionProjects/ClientServerC++/Data.txt",ios::app);
        }
        if(file.is_open()) {
            file << user << ";";
            file.close();
            return true;
        }else{
            return false;
        }
    }
    bool reWriteFile(){
        ofstream file;
        file.open ("/home/alejandrofrech/ClionProjects/ClientServerC++/Data.txt", ios::trunc);
        file.close();
        return true;
    }
    bool isUnique(string str){
        string line;
        ifstream file;
        file.open("/home/alejandrofrech/ClionProjects/ClientServerC++/Data.txt", ios::out);
        if (file.is_open()) {
            while (getline(file, line)) {
                if (strstr(line.c_str(),str.c_str())!=NULL)
                    return false;
            }
            file.close();
            return true;
        }
        cout<<"Error file not opened"<<endl;
        return false;
    }
    string getUsers(){
        string users=" ";
        string line;
        ifstream file("/home/alejandrofrech/ClionProjects/ClientServerC++/Data.txt", ios::out);
        if (file.is_open()) {
            while (getline(file, line)) {
                users+=line;
            }
            file.close();
        }
        return users;
    }

    string search(string str){
        string line;
        ifstream file("/home/alejandrofrech/ClionProjects/ClientServerC++/Data.txt", ios::out);
        if (file.is_open()) {
            while (getline(file, line)) {
                if (strstr(line.c_str(),str.c_str())!=NULL)
                    return line;
            }
            file.close();
        }
        cout<<"Error file not opened"<<endl;
        return " ";
    }

};


#endif //CLIENTSERVERC_FILEMANAGER_H
