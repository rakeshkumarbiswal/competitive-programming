// Server side C/C++ program to demonstrate Socket programming
#include<winsock2.h>
#include<iostream>
#include<windows.h>
#include<sstream>
#include<string>
#include<algorithm>
#define SCK_VERSION 0x202
using namespace std;
int main(int argc, char const *argv[])
{
    SOCKET ConSock;
    SOCKET ListenSock;
    SOCKADDR_IN address;
    int addrsize=sizeof(address);

    long ok;
    char MESSAGE[200];

    WSAData WSD;
    WORD DllVersion;
    DllVersion=MAKEWORD(2,1);
    ok=WSAStartup(DllVersion,&WSD);

    ConSock=socket(AF_INET,SOCK_STREAM,NULL);

    address.sin_addr.s_addr=inet_addr("127.0.0.1");
    address.sin_family=AF_INET;
    address.sin_port=htons(10102);

    ListenSock=socket(AF_INET,SOCK_STREAM,NULL);
    bind(ListenSock,(SOCKADDR*)&address,sizeof(address));
    listen(ListenSock,SOMAXCONN);

    //cout<<"SERVER WAITING FOR CONNECTIONS\n\n";

    while(true)
    {
        if(ConSock=accept(ListenSock,(SOCKADDR*)&address,&addrsize))
        {
            ok=recv(ConSock,MESSAGE,sizeof(MESSAGE),NULL);
            string msg;
            msg=MESSAGE;
            //cout<<"client says:\t"<<msg<<endl;
            sort(msg.begin(),msg.end());
            string reply=msg;
            //cout<<"Enter reply :\t";
            //cin>>reply;

            const char* s=reply.c_str();
            ok=send(ConSock,s,1024,NULL);

        }
    }
}
