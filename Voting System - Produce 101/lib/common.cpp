#include "common.h"
#include "stdlib.h"

void make_fifo(const char*file_path){
    if(access(file_path,F_OK)==-1){
        int res=mkfifo(file_path,0777);
        if(res!=0)
            exit(res);
        cout<<"Created at "<<file_path<<endl;
    }
}
int open_fifo(const char* file_path, int mode){
    cout<<"Opening from "<<file_path<<endl;
    return open(file_path,mode);
}