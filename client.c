#include <winsock2.h>
#include <ws2tcpip.h>

int main()
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[255];
    WSAStartup(MAKEWORD(2,0), &WSAData);
    /* Tout est configur� pour se connecter sur IRC, haarlem, Undernet. */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("62.250.14.6");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(6667);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    recv(sock, buffer, sizeof(buffer), 0);
    closesocket(sock);
    WSACleanup();
    return 0;
}