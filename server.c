int server_fd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in address;
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(8080);

bind(server_fd, (struct sockaddr *)&address, sizeof(address));
listen(server_fd, 3);

while(1) {
    int client_fd = accept(server_fd, NULL, NULL);
    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);
    
    char *response = "HTTP/1.1 200 OK\r\n\r\nHello World";
    write(client_fd, response, strlen(response));
    close(client_fd);
}