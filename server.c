#include <winsock2.h>

int main()
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);
    bind(sock, (SOCKADDR *)&sin, sizeof(sin));
    listen(sock, 0);
    while(1) /* Boucle infinie. Exercice : am�liorez ce code. */
    {
        int sinsize = sizeof(csin);
        if((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET)
        {
            send(csock, "Hello world!\r\n", 14, 0);
            closesocket(csock);
        }
    }
    /* On devrait faire closesocket(sock); puis WSACleanup(); mais puisqu'on a entr� une boucle infinie ... */
    return 0;
}