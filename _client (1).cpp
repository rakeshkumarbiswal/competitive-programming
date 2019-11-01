#include<winsock2.h>
#include<iostream>
#include<windows.h>
#include<cstring>
#include<sstream>
#include<string>
#define SCK_VERSION 0x202
using namespace std;
int main()
{
    SOCKET sock;
    SOCKADDR_IN address;
    long ok;
    char MESSAGE[200];

    WSAData WSD;
    WORD DllVersion;
    DllVersion=MAKEWORD(2,1);
    ok=WSAStartup(DllVersion,&WSD);

    while(true)
    {
        sock=socket(AF_INET,SOCK_STREAM,NULL);
        address.sin_addr.s_addr=inet_addr("127.0.0.1");
        address.sin_family=AF_INET;
        address.sin_port=htons(10102);

        connect(sock,(SOCKADDR*)&address,sizeof(address));

        string msg;
        int i;
        cin>>msg;
        const char * s =msg.c_str();
        //strcpy(s,msg);
        ok=send(sock,s,1024,NULL);

        ok= recv(sock,MESSAGE,sizeof(MESSAGE),NULL);
        string reply;
        reply=MESSAGE;
        cout<<reply<<endl;

    }
}
