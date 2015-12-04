//
// Created by alejandrofrech on 11-27-15.
//

#include "FileManager.h"

bool FileManager::writeUser(string user) {
    ofstream file;
    file.open ("Data.txt",ios::ate);
    if(file.is_open()) {
        file << user << "\n";
        file.close();
        return true;
    }else{
        return false;
    }
}

bool FileManager::reWriteFile() {
    ofstream file;
    file.open ("Data.txt", ios::in);
    if(file.is_open()) {
        file << " ";
        file.close();
        return true;
    }else{
        return false;
    }
}
bool FileManager::isUnique(string str) {
    string line;
    ifstream file("Data.txt", ios::out);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(str))
                return false;
        }
        file.close();
        return true;
    }
    cout<<"Error file not opened"<<endl;
    return false;
}

string FileManager::getUsers() {
    string users=" ";
    string line;
    ifstream file("Data.txt", ios::out);
    if (file.is_open()) {
        while (getline(file, line)) {
           users+=line;
        }
        file.close();
    }
    return users;
}

string FileManager::search(string str) {
    string line;
    ifstream file("Data.txt", ios::out);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(str))
                return line;
        }
        file.close();
    }
    cout<<"Error file not opened"<<endl;
    return " ";
}