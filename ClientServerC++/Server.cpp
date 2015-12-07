#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "FileManager.h"
using namespace std;
int main() {
    FileManager *fm= new FileManager();
    int fd, newsockfd, portno , rc ;
    socklen_t clilen;
    char buf[2042];

    struct sockaddr_in serv_addr, cli_addr;
    int n;
    // create a socket
    // socket(int domain, int type, int protocol)
    fd =  socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
        printf("%s\n","ERROR opening socket");

    // clear address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = 1060;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        printf("%s\n","ERROR on binding");
    listen(fd,5);
    clilen = sizeof(cli_addr);

    while (true) {
        newsockfd = accept(fd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            printf("%s\n","ERROR on accept");
       while ( (rc=read(newsockfd,buf,sizeof(buf))) > 0) {
           char * tokens;
           tokens = strtok (buf,"\n");
           printf("%s\n",tokens);
           if(strcmp(tokens,"Add")==0){
               tokens = strtok (NULL,"\n");
               string res=" ";
               string str(tokens);
               if(fm->writeUser(str)) {
                   printf("%s\n", "si lo escribi");
                   res = "Yes";
               } else {
                   printf("%s\n", "no lo escribi");
                   res = "No";
               }
               strcpy(buf,res.c_str());
               printf("%s\n",buf);
               rc=send(newsockfd, buf,sizeof(buf),0);
           }
           if(strcmp(tokens,"Show")==0){
               tokens = strtok (NULL,"\n");
               string u;
               string str(tokens);
               u=fm->search(str);
               strcpy(buf,u.c_str());
               send(newsockfd, buf,sizeof(buf),0);
           }
           if(strcmp(tokens,"Delete")==0){
               tokens = strtok (NULL,"\n");
               printf("%s\n",tokens);
               string u=fm->getUsers();
               vector<string>userlist=fm->split(u,";");
               fm->reWriteFile();
               string res="NO";
               vector<string> tok;
               for(int i=0;i<userlist.size();i++){
                   if(userlist[i].find(string(tokens))){
                       fm->writeUser(userlist[i]);
                   }else{
                       res="Yes";
                   }
               }
               strcpy(buf,res.c_str());
               rc=send(newsockfd, buf,sizeof(buf),0);
           }
           if(strcmp(tokens,"Email")==0){

           }
       }
         if (rc == 0) {
            printf("EOF\n");
            close(newsockfd);
        }
    }
}