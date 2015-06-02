/*************************************************************************
    > File Name: socket.h
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月02日 星期二 16时11分07秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<error.h>
#define MAX_PORT 128
#define IP


namespace SOCKET
{
	class Socket
	{
		public:
			Socket(const std::string& port):m_ip(IP),m_port(atoi(port.c_str())){}

			void socket_init()
			{
				server_sock = socket(AF_INET, SOCK_STREAM, 0);//ipv4 TCP
				if(-1 == server_sock)
				{
					perror("socket init");
				}
			}

			int set_nonblock(int& sockfd)
			{
				
			}

			void socket_bind()
			{

			}

			void socket_listen()
			{

			}

			void socket_accept()
			{

			}

			void socket_connect()
			{

			}

			void sendn(const int& sockfd, const char* msg, const int& send_len)
			{

			}

			void socket_send(const int& sockfd, const char* msg)
			{

			}

			void recvn(const int& sockfd, char* msg, const int& recv_len)
			{

			}

			int socket_recv(const int& sockfd, char* msg)
			{

			}

		public:
			int server_sock;

		private:
			const std::string m_ip;
			const int m_port;
			struct sockaddr_in server_addr;
	};
}
