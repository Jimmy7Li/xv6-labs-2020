#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char *argv[])
{
    int p2c[2];
    int c2p[2];
    pipe(p2c);
    pipe(c2p);
    char buf='p';
    int pid=fork();
    if(pid<0)
    {
        fprintf(2,"fork() error\n");
        close(p2c[0]);
        close(p2c[1]);
        close(c2p[0]);
        close(c2p[1]);
        exit(1);
    }
    else if(pid==0)
    {
        close(p2c[1]);
        close(c2p[0]);
        read(p2c[0],&buf,1);
        fprintf(1,"%d: received ping\n",getpid());
        write(c2p[1],&buf,1);
        close(p2c[0]);
        close(c2p[1]);
        exit(0);
    }
    else
    {
        close(p2c[0]);
        close(c2p[1]);
        write(p2c[1],&buf,1);
        read(c2p[0],&buf,1);
        fprintf(1,"%d: received pong\n",getpid());
        close(p2c[1]);
        close(c2p[0]);
        exit(0);
    }
}