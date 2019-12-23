#include<sys/socket.h>
#include<netinet/in.h> /* sockaddr_in{} and other Internet defns */
#include<unistd.h>	   //fork
#include<sys/types.h> //fork
#include<cstring>
#include<stdlib.h>
#include<iostream>
#include<netinet/in.h> //inet_pton
#include<arpa/inet.h>  //inet_pton

#define	SERV_PORT		 9877
#define	LISTENQ		1024	/* 2nd argument to listen() */
#define MAXLINE 1024
using namespace std;
void str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (fgets(sendline, MAXLINE, fp) != NULL) {

		write(sockfd, sendline, strlen(sendline));

		if (read(sockfd, recvline, MAXLINE) == 0)
			cout<<("str_cli: server terminated prematurely");

		fputs(recvline, stdout);
	}
}

int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		cout<<("usage: tcpcli <IPaddress>");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
