#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <netinet/in.h>
#include <netdb.h>
#include "User.h"
#include "Validations.h"
using namespace std;


int main(int argc, char *argv[]) {

    int fd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[2042];
    portno = 1060;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
       printf("%s\n","ERROR opening socket");
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        printf("%s\n","ERROR connecting");
    else
    printf("Connected.\n");

    int op;
    do{
        cout<<"1) Add User"<<endl;
        cout<<"2) Show User"<<endl;
        cout<<"3) Delete User"<<endl;
        cout<<"4) Send  User"<<endl;
        cin>>op;

        switch (op){
            case 1:
            {
                string username, name, email, cedula, date, imgurl;
                cout << "Enter Username" << endl;
                cin >> username;
                cout << "Enter Name" << endl;
                cin >> name;
                cout << "Enter Email" << endl;
                cin >> email;
                cout << "Enter Id Number" << endl;
                cin >> cedula;
                cout << "Enter Birth Date" << endl;
                cin >> date;
                cout << "Enter Image url" << endl;
                cin >> imgurl;
                Validations *val = new Validations();
                if (val->verifyEmail(email) && val->verifyCedula(cedula) && val->verifyUser(username) && val->verifyDate(date)) {
                    User *user = new User(username, name, email, cedula, date, imgurl);
                    stringstream ss;
                    ss << "Add" << "\n" << user->to_s();
                    string userToAdd = ss.str();
                    strcpy(buf, userToAdd.c_str());
                    write(fd, buf, sizeof(buf));
                    printf("%s\n",buf);
                    read(fd, buf, sizeof(buf));
                } else
                    cout << "Error user not added!!!!!!!" << endl;
                break;
            }
            case 2:
            {
                string usr;
                cout << "Enter Username" << endl;
                cin >> usr;
                stringstream ss;
                ss << "Show" << "\n" << usr;
                string userToShow = ss.str();
                strcpy(buf, userToShow.c_str());
                write(fd, buf, sizeof(buf));
                read(fd, buf, sizeof(buf));
                printf("%s\n",buf);
                if (strcmp(buf, " ") != 0){
                    char * tokens=strtok(buf,",");

                    cout<<"----User Info--------"<<endl;
                    cout<<"Username : "<<tokens<<endl;
                    tokens=strtok(NULL,",");
                    cout<<"Name : "<<tokens<<endl;
                    tokens=strtok(NULL,",");
                    cout<<"Email : "<<tokens<<endl;
                    tokens=strtok(NULL,",");
                    cout<<"Identity Card : "<<tokens<<endl;
                    tokens=strtok(NULL,",");
                    cout<<"Birth Date  : "<<tokens<<endl;
                    tokens=strtok(NULL,",");
                    cout<<"Image Url  : "<<tokens<<endl;
                }else{
                    cout<<" Error user not in database!!!"<<endl;
                }
                break;
            }
            case 3:
            {
                string usr;
                cout << "Enter Username to Delete" << endl;
                cin >> usr;
                stringstream ss;
                ss << "Delete" << "\n" << usr;
                string userToDelete = ss.str();
                strcpy(buf, userToDelete.c_str());
                write(fd, buf, sizeof(buf));
                read(fd, buf, sizeof(buf));
                if (strcmp(buf, "Yes") == 0)
                    cout<<"User Succesfully deleted!!!!"<<endl;
                else
                    cout<<"Error User not deleted or dosent exist!!"<<endl;
                break;
            }
            case 4:
            {
                string usr, email;
                cout << "Enter Username to send" << endl;
                cin >> usr;
                cout << "Enter Email to send user" << endl;
                cin >> usr;
                stringstream ss;
                ss << "Email" << "\n" << usr << "\n"<<email;
                string userToEmail = ss.str();
                strcpy(buf, userToEmail.c_str());
                write(fd, buf, sizeof(buf));
                read(fd, buf, sizeof(buf));
                if (strcmp(buf, "Yes") == 0)
                    cout<<"Email Succesfully sent!!!!"<<endl;
                else
                    cout<<"Error not sentt!!"<<endl;
                break;
            }
        }
    }while(op<5);
    close(fd);
    return 0;
}