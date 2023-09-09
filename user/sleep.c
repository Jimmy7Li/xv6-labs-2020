#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

//自己的版本
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

//参考别人的版本
// int main(int argc,char *argv[])
// {
//     if(argc!=2)
//     {
//         fprintf(2,"usage: sleep<time>\n"); 
//         exit(1);
//     }
//     sleep(atoi(argv[1]));
//     exit(0);
// }
