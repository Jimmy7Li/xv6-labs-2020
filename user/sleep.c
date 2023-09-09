#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc,char *argv[])
{
    if(argc==1)
    {
        write(1,"please input parameter\n",24);  
    }
    else{
        int sleeptime=atoi(argv[1]);
        sleep(sleeptime);
    }
    exit(0);
}