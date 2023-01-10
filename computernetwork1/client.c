#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>//

#define MAX 80 
#define PORT 9090 
#define SA struct sockaddr 

void func(int sockfd) { 
    char buff[MAX]; 
    int n; 
    while (1){ 
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        //从控制台读取消息
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 

        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
} 
  
int main(int argc, char const *argv[]){ 
    int sockfd; //连接符
    struct sockaddr_in servaddr; 
  
    // 套接字创建
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); //初始化结构体
  
    //分配IP，端口
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
     //连接服务器，如果非0，则连接失败
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
        
    func(sockfd); 
  
    // 关闭套接字
    close(sockfd); 
} 