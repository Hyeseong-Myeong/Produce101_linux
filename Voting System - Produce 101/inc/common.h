#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#define FIFO_CLIENT_PATH "../res/c_%d_fifo"
#define FIFO_SERVER_PATH "../res/s_fifo"

typedef struct DATA{
    pid_t pid;
    int data;
}data_t;

void make_fifo(const char* file_path);
int open_fifo(const char* file_path, int mode);
