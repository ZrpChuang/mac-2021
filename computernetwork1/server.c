#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 9090//设置端口
#define SA struct sockaddr 
  

void func(int sockfd) { 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    while(1) { 
        bzero(buff, MAX); 
  
        //读取客户端发送的消息
        read(sockfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        //将读取内容原封不动地发送回去
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // 将缓冲区发送给客户端
        write(sockfd, buff, sizeof(buff)); 
  
        // 如果msg包含“exit”，那么服务器退出和聊天结束。
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 
  
int main(int argc, char const *argv[]){

    int sockfd, connfd, len;//创建的返回值
    struct sockaddr_in servaddr, cli; //内置的一个结构体
  
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
    //socket函数
    //int socket(int af, int type, int protocol);
    // AF_INET 表示是ipv4的意思
    //SOCK_STREAM（流格式套接字/面向连接的套接字） 和 SOCK_DGRAM（数据报套接字/无连接的套接字）
    //protocol 表示传输协议，常用的有 IPPROTO_TCP 和 IPPTOTO_UDP，分别表示 TCP 传输协议和 UDP 传输协议。

    if (sockfd == -1) { //检查套接字是否建立成功
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else printf("Socket successfully created..\n"); 
    //初始化服务端socket信息

    bzero(&servaddr, sizeof(servaddr)); 
  
    //使用默认的ip和port 
    servaddr.sin_family = AF_INET; //使用ipv4
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //具体ip地址
    servaddr.sin_port = htons(PORT); //端口
  
    //绑定指定ip和端口
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) 
    //这里我们使用 sockaddr_in 结构体，然后再强制转换为 sockaddr 类型
    //sockaddr 和 sockaddr_in 的长度相同，都是16字节，只是将IP地址和端口号合并到一起，
    //用一个成员 sa_data 表示。要想给 sa_data 赋值，必须同时指明IP地址和端口号，例如”127.0.0.1:80“，
    //遗憾的是，没有相关函数将这个字符串转换成需要的形式，也就很难给 sockaddr 类型的变量赋值，所以使用 
    //sockaddr_in 来代替。这两个结构体的长度相同，强制转换类型时不会丢失字节，也没有多余的字节。

    { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // 现在服务器已经准备好监听
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
    

    connfd = accept(sockfd, (SA*)&cli, &len); 
     //处理来自客户端的连接
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    func(connfd); 
    // 关闭套接字
    close(sockfd); 
} 

// 思考：
// 环境：m1macbookpro arm64(底层操作系统为UNIX操作系统)
// 用c语言写了一个简单的客户进程与服务器进程的通信。
// 服务器程序的编写：