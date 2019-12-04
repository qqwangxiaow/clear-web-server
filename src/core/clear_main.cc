#include<sys/socket.h>
int main(int argc,char *argv[])
{
    int listenfd;
    /*
    if(clear_init()==-1)
    {
        return 1;
    }
    if(clear_get_option()==-1)
    {
        return 1;
    }
    */
    listenfd=open_listenfd(argv[1]);
    while(1)
    {
        
        



    }

}