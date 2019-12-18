#include<sys/socket.h>
#include<netinet/in.h> /* sockaddr_in{} and other Internet defns */
#include<unistd.h>	   //fork
#include<sys/types.h> //fork
#include<cstring>
#include<stdlib.h>
#define	SERV_PORT		 9877
#define	LISTENQ		1024	/* 2nd argument to listen() */
using namespace std;
void
str_echo(int sockfd)
{
	long		arg1, arg2;
	ssize_t		n;
	char		line[MAXLINE];

	for ( ; ; ) {
		if ( (n = Readline(sockfd, line, MAXLINE)) == 0)
			return;		/* connection closed by other end */

		if (sscanf(line, "%ld%ld", &arg1, &arg2) == 2)
			snprintf(line, sizeof(line), "%ld\n", arg1 + arg2);
		else
			snprintf(line, sizeof(line), "input error\n");

		n = strlen(line);
		Writen(sockfd, line, n);
	}
}

int main(int argc, char **argv)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;

	if(listenfd = socket(AF_INET, SOCK_STREAM, 0))
		return -1;

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        return -1;

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
}
