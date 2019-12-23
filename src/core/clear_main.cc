#include<sys/socket.h>
#include<netinet/in.h> /* sockaddr_in{} and other Internet defns */
#include<unistd.h>	   //fork
#include<sys/types.h> //fork
#include<cstring>
#include<stdlib.h>
#include<iostream>
#define	SERV_PORT		 9877
#define	LISTENQ		1024	/* 2nd argument to listen() */
#define MAXLINE 1024
using namespace std;
void
Writen(int fd, void *ptr, size_t nbytes)
{
	if (write(fd, ptr, nbytes) != nbytes)
		cout<<("writen error");
}
void str_echo(int sockfd)
{
	ssize_t		n;
	char		buf[MAXLINE];
again:
	while ( (n = read(sockfd, buf, MAXLINE)) > 0)
		Writen(sockfd, buf, n);

	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		cout<<("str_echo: read error");
}

int main(int argc, char **argv)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	cout<<"goooooooood";
	if(listenfd = socket(AF_INET, SOCK_STREAM, 0))
		return -1;

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	 // 最大等待队列长LISTENQ
    if(listen(listenfd, LISTENQ) == -1)
        return -1;

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		if(connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &clilen)<0)
			return -1;

		if ( (childpid = fork()) == 0) {	/* child process */
			close(listenfd);	/* close listening socket */
			str_echo(connfd);	/* process the request */
			exit(0);
		}
		close(connfd);			/* parent closes connected socket */
	}
	cout<<"baaaaaaad";
}
