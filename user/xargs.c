#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char* argv[])
{
    if(argc<2){
        fprintf(2,"usage: xargs [command]\n");
        exit(1);
    }
    char buf[16];
    read(0,buf,16);

    char *xargv[16];
    int xargc=0;
    for(int i=1;i<argc;i++)
    {
        xargv[xargc++]=argv[i];
    }

    char *p=buf;
    for(int i=0;i<16;i++){
        if(buf[i]=='\n'){
            int pid=fork();
            if(pid<0)
            {
                fprintf(2,"fork() failed\n");
                exit(1);
            }
            else if (pid==0)
            {
                buf[i]=0;
                xargv[xargc++]=p;
                xargv[xargc++]=0;
                exec(xargv[0],xargv);
                exit(0);
            }
            else{
                p=buf+i+1;
                wait(0);
            }
        }
    }
    wait(0);
    exit(0);
}