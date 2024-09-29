#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <Winsock2.h>
#include <string>

int main() {
    std::cout << "Attempting to create a server...\n";

    SOCKET wsocket;
    SOCKET new_wsocket;
    WSADATA wsaData;
    struct sockaddr_in server;
    int server_len;
    int BUFFER_SIZE = 30720;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Could not initialize Winsock\n";
        return 1;
    }

    // Creating a socket
    wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (wsocket == INVALID_SOCKET) {
        std::cout << "Could not create socket\n";
        WSACleanup();
        return 1;
    }

    // Bind socket to address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8081);
    server_len = sizeof(server);

    if (bind(wsocket, (SOCKADDR*)&server, server_len) != 0) {
        std::cout << "Could not bind socket\n";
        closesocket(wsocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(wsocket, 20) != 0) {
        std::cout << "Could not start listening!\n";
        closesocket(wsocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Listening on 127.0.0.1:8081\n";

    int bytes = 0;
    while (true) {
        new_wsocket = accept(wsocket, (SOCKADDR*)&server, &server_len);
        if (new_wsocket == INVALID_SOCKET) {
            std::cout << "Could not accept connection\n";
            continue;
        }

        // Read client request
        char buff[30720] = { 0 };
        bytes = recv(new_wsocket, buff, BUFFER_SIZE, 0);
        if (bytes == 0) {
            std::cout << "Connection closed by client\n";
            closesocket(new_wsocket);
            continue;
        }
        else if (bytes < 0) {
            std::cout << "Could not read client request\n";
            closesocket(new_wsocket);
            continue;
        }

        // Prepare HTTP response
        std::string serverMessage = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
        std::string response = "<html><h1>Hello world!</h1></html>";
        serverMessage.append(std::to_string(response.size()));
        serverMessage.append("\n\n");
        serverMessage.append(response);

        int bytesSent = 0;
        int totalBytesSent = 0;
        while (totalBytesSent < serverMessage.size()) {
            bytesSent = send(new_wsocket, serverMessage.c_str() + totalBytesSent, serverMessage.size() - totalBytesSent, 0);
            if (bytesSent < 0) {
                std::cout << "Could not send response\n";
                break;
            }
            totalBytesSent += bytesSent;
        }
        std::cout << "Sent response to client\n";

        closesocket(new_wsocket);
    }

    closesocket(wsocket);
    WSACleanup();

    return 0;
}
