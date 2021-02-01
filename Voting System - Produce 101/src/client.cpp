#include "common.h"
int main()
{
    int server_fd = open_fifo(FIFO_SERVER_PATH, O_WRONLY);
    int client_fd = 0;
    data_t buf;
    char name[50];
    buf.pid = getpid();
    char client_fifo[256];
    sprintf(client_fifo, FIFO_CLIENT_PATH, buf.pid);
    make_fifo(client_fifo);
    int num;
    int input;
    int read_bytes = 0;
    while (1)
    {
        cout << "**********Produce IoT**********" << endl;
        cout << "1. vote" << endl;
        cout << "2.See Infomation of one singer" << endl;
        cout << "3. See all singers Infomation" << endl;
        cout << "4. See Graph of one singer" << endl;
        cout << "0. exit" << endl;
        cin >> input;
        buf.data = input;
        if (input == 0)
            break;
        write(server_fd, &buf, sizeof(buf));
        client_fd = open(client_fifo, O_RDONLY);
        if (client_fd != -1)
        {
            read_bytes = read(client_fd, &input, sizeof(input));
            if (read_bytes > 0)
            {
                if (input == 1)
                {
                    system("clear");
                    cout << "Input name of singer to vote>> ";
                    cin >> name;
                    write(server_fd, &name, sizeof(name));
                    char text[99999];
                    read(client_fd, &text, sizeof(text));
                    cout << text << endl;
                    usleep(1500000);
                    system("clear");
                }
                else if (input == 2)
                {
                    system("clear");
                    cout << "Input Name>> ";
                    cin >> name;
                    write(server_fd, &name, sizeof(name));
                    char info[99999];
                    read(client_fd, &info, sizeof(info));
                    cout << info << endl;
                    usleep(3000000);
                    system("clear");
                }
                else if (input == 3)
                {
                    system("clear");
                    int num;
                    read(client_fd, &num, sizeof(num));
                    if (num == 0)
                    {
                        char info[99999];
                        read(client_fd, &info, sizeof(info));
                        cout << info << endl;
                    }
                    for (int i = 0; i < num; i++)
                    {
                        char info[99999];
                        read(client_fd, &info, sizeof(info));
                        cout << info << endl;
                    }
                    usleep(5000000);
                    system("clear");
                }
                else if (input == 4)
                {
                    system("clear");
                    cout << "Input Name>> ";
                    cin >> name;
                    write(server_fd, &name, sizeof(name));
                    char info[99999];
                    read(client_fd, &info, sizeof(info));
                    cout << info;
                    system("chmod +x graph.sh");
                    system("./graph.sh");
                    usleep(7000000);
                    system("clear");
                }
                else if (input == 5)
                {
                    system("clear");
                    cout << "Voting is not available" << endl;
                    usleep(1500000);
                    system("clear");
                }
                else
                {
                    system("clear");
                    cout << "Wrong Input" << endl;
                    usleep(1500000);
                    system("clear");
                }
            }
            close(client_fd);
        }
    }
    close(server_fd);
    unlink(client_fifo);
}