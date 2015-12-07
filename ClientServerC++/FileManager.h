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
#include <vector>
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
            file << user <<";"<< "\n";
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
    bool isUnique(string str,int pos){
        string users=this->getUsers();
        vector<string>userlist=this->split(users,";");
        if(userlist.size()<=1)
            return true;

        for(int i=0;i<userlist.size();i++){
            vector<string>tokens=split(userlist[i],",");
            if(tokens.size()<=1)
                return true;
            if(str==tokens[pos]){
                return false;
            }
        }
        return true;
    }

    string getUsers(){
        string users;
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
        string users=this->getUsers();
        vector<string>userlist=this->split(users,";");
        for(int i=0;i<userlist.size();i++){
            vector<string>tokens=split(userlist[i],",");
            if(str==tokens[0]){
                return userlist[i];
            }
        }
        return " ";
    }

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::string delims = std::string(1, delim);
        tokenize(s, elems, delims);
        return elems;
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        return split(s, delim, elems);
    }

    std::vector<std::string> &split(const std::string &s, const std::string& delims, std::vector<std::string> &elems) {
        tokenize(s, elems, delims);
        return elems;
    }

    std::vector<std::string> split(const std::string &s, const std::string& delims) {
        std::vector<std::string> elems;
        return split(s, delims, elems);
    }

    template < class ContainerT >
    void tokenize(const std::string& str, ContainerT& tokens,
                  const std::string& delimiters = " ", const bool trimEmpty = false)
    {

        std::string::size_type pos, lastPos = 0;
        while(true)
        {
            pos = str.find_first_of(delimiters, lastPos);
            if(pos == std::string::npos)
            {

                pos = str.length();

                if(pos != lastPos || !trimEmpty) {
                    tokens.push_back(typename ContainerT::value_type(str.data()+lastPos, (typename ContainerT::value_type::size_type)pos-lastPos));
                }

                break;
            }
            else
            {
                if(pos != lastPos || !trimEmpty) {
                    tokens.push_back(typename ContainerT::value_type(str.data()+lastPos, (typename ContainerT::value_type::size_type)pos-lastPos));
                }
            }

            lastPos = pos + 1;
        }
    };

};

#endif //CLIENTSERVERC_FILEMANAGER_H
