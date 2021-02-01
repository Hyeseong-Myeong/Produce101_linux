#include "common.h"
#include "manager.h"
#include "viewer.h"
#include "auto.h"
#include "singer.h"
#include "Viewer_v.h"
#include <string.h>
#include <thread>
void m(Manager &manager, Singer &singer, Auto &oto, Viewer &viewer)
{
    string mdstr;
    int round = manager.getround();
    int mode;
    int quit = 0;
    while (quit != 1)
    {
        cout << "Manager command" << endl;
        if (!manager.checktime() && manager.getround() != round)
        {
            manager.grading(singer);
            round = manager.getround();
        }
        cout << "1. Vote" << endl;
        cout << "2. See Infomation of one singer" << endl;
        cout << "3. See all singers Infomation" << endl;
        cout << "4. See Graph of one singer" << endl;
        cout << "5. Insert New Singer" << endl;
        cout << "6. Start AutoMode" << endl;
        cout << "7. Give Benefit" << endl;
        cout << "8. Start vote" << endl;
        cout << "9. Remove Singer" << endl;
        cout << "0. exit" << endl;
        cin >> mdstr;
        mode = atoi(mdstr.c_str());
        if (!isdigit(mode))
        {
            switch (mode)
            {
            case 1:
                if (!manager.checktime())
                {
                    system("clear");
                    cout << "Voting is not available." << endl;
                    usleep(1500000);
                    system("clear");
                    break;
                }
                viewer.vote(singer);
                system("clear");
                break;
            case 2:
                viewer.see_info(singer);
                break;
            case 3:
                viewer.see_info_all(singer);
                break;
            case 4:
                if (!manager.checktime())
                {
                    viewer.see_graph(singer, manager.getround());
                }
                else
                {
                    system("clear");
                    cout << "voting in progress" << endl;
                    usleep(1500000);
                    system("clear");
                }
                break;
            case 5:
                manager.change(singer);
                system("clear");
                break;
            case 6:
                oto.startAuto(singer, manager.checktime());
                break;
            case 7:
                oto.makeGroup(singer);
                oto.giveBenefit(singer);
                break;
            case 8:
                manager.startvote(singer);
                break;
            case 9:
                manager.erase(singer);
                break;
            case 0:
                quit = 1;
                system("clear");
                break;
            default:
                system("clear");
                cout << "Wrong input" << endl;
                usleep(1500000);
                system("clear");
                break;
            }
        }
    }
}
void s(Manager &manager, Singer &singer, Auto &oto, Viewer &viewer, Viewer_v &viewer_v)
{
    make_fifo(FIFO_SERVER_PATH);
    int server_fd = open_fifo(FIFO_SERVER_PATH, O_RDONLY);
    cout << "\t\t\tClient connected" << endl;
    int client_fd = 0;
    char client_fifo[256];
    pid_t c_pid;
    data_t buf;
    int num;
    int nnum;
    int read_bytes = 0;
    int input;
    char name[50];
    string mdstr;
    int round = manager.getround();
    while (1)
    {
        if (!manager.checktime() && manager.getround() != round)
        {
            manager.grading(singer);
            round = manager.getround();
        }
        read_bytes = read(server_fd, &buf, sizeof(buf));
        if (read_bytes <= 0)
            break;
        c_pid = buf.pid;
        input = buf.data;
        cout << "\t\t\t\t Data from Client: " << c_pid << ", " << input << endl;
        sprintf(client_fifo, FIFO_CLIENT_PATH, c_pid);
        client_fd = open(client_fifo, O_WRONLY);

        if (client_fd != -1)
        {
            if (input == 1)
            {
                if (!manager.checktime())
                {
                    input = 5;
                    write(client_fd, &input, sizeof(input));
                }
                else
                {
                    write(client_fd, &input, sizeof(input));
                    read(server_fd, &name, sizeof(name) * 50);
                    string info = viewer_v.vote(singer, name);
                    char ginfo[99999];
                    sprintf(ginfo, "%s", info.c_str());
                    write(client_fd, &ginfo, sizeof(ginfo));
                }
            }
            else if (input == 2)
            {
                write(client_fd, &input, sizeof(input));
                read(server_fd, &name, sizeof(name) * 50);
                string info = viewer_v.see_info(singer, name);
                char ginfo[99999];
                sprintf(ginfo, "%s", info.c_str());
                write(client_fd, &ginfo, sizeof(ginfo));
            }
            else if (input == 3)
            {
                write(client_fd, &input, sizeof(input));
                int num = singer.singer_num();
                write(client_fd, &num, sizeof(num));
                if (num == 0)
                {
                    char info[] = "No singers\n";
                    write(client_fd, &info, sizeof(info));
                }
                for (int i = 0; i < num; i++)
                {
                    string info = viewer_v.see_info_all(singer, i);
                    char ginfo[99999];
                    sprintf(ginfo, "%s", info.c_str());
                    write(client_fd, &ginfo, sizeof(ginfo));
                }
            }
            else if (input == 4)
            {
                write(client_fd, &input, sizeof(input));
                read(server_fd, &name, sizeof(name) * 50);
                string info = viewer_v.see_graph(singer, manager.getround(), name);
                char ginfo[99999];
                sprintf(ginfo, "%s", info.c_str());
                write(client_fd, &ginfo, sizeof(ginfo));
            }
            else
            {
                write(client_fd, &input, sizeof(input));
            }
            close(client_fd);
        }
    }
    manager.file_save(singer);
    close(server_fd);
    unlink(FIFO_SERVER_PATH);
}

int main()
{
    Manager manager;
    Singer singer;
    Viewer viewer;
    Auto oto;
    Viewer_v viewer_v;
    manager.file_open(singer);
    thread t1(m, ref(manager), ref(singer), ref(oto), ref(viewer));
    thread t2(s, ref(manager), ref(singer), ref(oto), ref(viewer), ref(viewer_v));
    t2.join();
    t1.join();
}
