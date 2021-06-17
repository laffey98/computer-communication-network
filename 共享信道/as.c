#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <unistd.h>

//人少需大：定时轮流制。人多需少：延迟制。
//人多需大：加长型延时制或定时轮流制或组间定时轮流组内延迟制
//目标：保证平等，提高信道利用率
//主动与被动达成和解

#define MAX_ASK 2
#define CI 10
#define FREQUENCY1 5
#define FREQUENCY2 2
#define FREQUENCY3 3
#define FREQUENCY4 7
#define MAX_delay_ndoe 200
#define node_num 100
#define TIME 2000
int ask_num, node1, node2, t_time = 0, t_node = -1, hh = 0, nooo = 0;
int ask[20];
int node[node_num];
int delay_node[MAX_delay_ndoe];
float hhh;
float total = 0, use = 0, nto = 0;

void calcu_delay_node(int n) {
    for (int i = 0; i < n; i++) {
        node[delay_node[i]] = rand() % 5;
    }
}

void asking() {
    ask_num = rand() % (MAX_ASK + 1);
    if (hh % FREQUENCY1 == 0) {
        ask_num = 0;
    }
    if (hh % FREQUENCY2 == 0) {
        ask_num = 0;
    }
    if (hh % FREQUENCY3 == 0) {
        ask_num = 0;
    }
    if (hh % FREQUENCY4 == 0) {
        ask_num = 0;
    }
    if (ask_num == MAX_ASK) {
        do node1 = rand() % node_num;
        while (delay_node[node1] != -1);
        do node2 = rand() % node_num;
        while ((node1 == node2) || (delay_node[node2] != -1));
    }
    if (ask_num == 1) {
        do node1 = rand() % node_num;
        while (delay_node[node1] != -1);
        // node1 = rand() % node_num;
        node2 = -1;
        // t_time = rand() % 3 + 1;
    }
    if (ask_num == 0) {
        node1 = -1;
        node2 = -1;
    }
    // printf("asking nodes 1:%d 2:%d \n", node1, node2);
}

void using() {
    int n = 0;
    // int real_ask_num = 0;
    for (int i = 0; i < MAX_delay_ndoe; i++) {
        if (delay_node[i] != -1) n++;
    }
    // real_ask_num += n;
    if (t_time == 0) {
        if (ask_num == 0) {
            switch (n) {
                case 0:
                    t_node = -1;
                    break;
                case 1:
                    t_time = rand() % 2 + 1;
                    t_node = delay_node[0];
                    break;
                default:
                    calcu_delay_node(n);
                    t_node = -1;
                    break;
            }
        }
        if (ask_num == 1) {
            switch (n) {
                case 0:
                    t_time = rand() % 2 + 1;
                    t_node = node1;
                    break;
                default:
                    node[node1] = rand() % 5;
                    calcu_delay_node(n);
                    t_node = -1;
                    break;
                    /*case 1:
                        node[node1] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 2:
                        node[node1] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 3:
                        node[node1] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 4:
                        node[node1] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        node[delay_node[3]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 5:
                        node[node1] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        node[delay_node[3]] = rand() % 5;
                        node[delay_node[4]] = rand() % 5;
                        t_node = -1;
                        break;*/
            }
        }
        if (ask_num == 2) {
            // printf("t_time == 0,1:%d 2:%d ", node[node1], node[node2]);
            switch (n) {
                case 0:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    t_node = -1;
                    break;
                default:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    calcu_delay_node(n);
                    // node[delay_node[0]] = rand() % 5;
                    t_node = -1;
                    break;
                    /*case 1:
                        node[node1] = rand() % 5;
                        node[node2] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 2:
                        node[node1] = rand() % 5;
                        node[node2] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 3:
                        node[node1] = rand() % 5;
                        node[node2] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 4:
                        node[node1] = rand() % 5;
                        node[node2] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        node[delay_node[3]] = rand() % 5;
                        t_node = -1;
                        break;
                    case 5:
                        node[node1] = rand() % 5;
                        node[node2] = rand() % 5;
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        node[delay_node[3]] = rand() % 5;
                        node[delay_node[4]] = rand() % 5;
                        t_node = -1;
                        break;*/
            }
        }
    } else {
        if (ask_num == 0) {
            switch (n) {
                case 0:
                    break;
                default:
                    calcu_delay_node(n);
                    // node[delay_node[0]] = rand() % 5;
                    break;
                    /*case 1:
                        node[delay_node[0]] = rand() % 5;
                        break;
                    case 2:
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        break;
                    case 3:
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        break;
                    case 4:
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        node[delay_node[3]] = rand() % 5;
                        break;
                    case 5:
                        node[delay_node[0]] = rand() % 5;
                        node[delay_node[1]] = rand() % 5;
                        node[delay_node[2]] = rand() % 5;
                        node[delay_node[3]] = rand() % 5;
                        node[delay_node[4]] = rand() % 5;
                        break;*/
            }
        }
        if (ask_num == 1) {
            node[node1] = rand() % 5;
            // node[delay_node[0]] = rand() % 5;
            calcu_delay_node(n);
            /*switch (n) {
                case 0:
                    node[node1] = rand() % 5;
                    break;
                case 1:
                    node[node1] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    break;
                case 2:
                    node[node1] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    break;
                case 3:
                    node[node1] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    node[delay_node[2]] = rand() % 5;
                    break;
                case 4:
                    node[node1] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    node[delay_node[2]] = rand() % 5;
                    node[delay_node[3]] = rand() % 5;
                    break;
                case 5:
                    node[node1] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    node[delay_node[2]] = rand() % 5;
                    node[delay_node[3]] = rand() % 5;
                    node[delay_node[4]] = rand() % 5;
                    break;
        }*/
            // printf("t_time == %d,1:%d ", t_time, node[node1]);
        }
        if (ask_num == 2) {
            node[node1] = rand() % 5;
            node[node2] = rand() % 5;
            calcu_delay_node(n);
            /*switch (n) {
                case 0:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    break;
                case 1:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    break;
                case 2:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    break;
                case 3:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    node[delay_node[2]] = rand() % 5;
                    break;
                case 4:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    node[delay_node[2]] = rand() % 5;
                    node[delay_node[3]] = rand() % 5;
                    break;
                case 5:
                    node[node1] = rand() % 5;
                    node[node2] = rand() % 5;
                    node[delay_node[0]] = rand() % 5;
                    node[delay_node[1]] = rand() % 5;
                    node[delay_node[2]] = rand() % 5;
                    node[delay_node[3]] = rand() % 5;
                    node[delay_node[4]] = rand() % 5;
                    break;
            }*/
            // printf("t_time == %d,1:%d,2:%d ", t_time,
            // node[node1],node[node2]);
        }
        t_time--;
    }
    // printf("now node%d is using,remaining time:%d", t_node, t_time);
    memset(delay_node, -1, sizeof(delay_node));
    // printf("t_time == %d", t_time);
}

void node_op() {
    // printf("\nnode:\n");
    for (int i = 0; i < node_num; i++) {
        if (node[i] != -1) {
            // printf("%d:%d \n", i, node[i]);
        }
        if (node[i] == 0) {
            for (int a = 0; a < MAX_delay_ndoe; a++) {
                if (delay_node[a] == -1) {
                    delay_node[a] = i;
                    break;
                }
                if ((delay_node[MAX_delay_ndoe - 1] != -1) &&
                    (delay_node[MAX_delay_ndoe - 1] != i)) {
                    printf("\nboommmmmmmmmmmmmmmmm!\n");
                    getchar();
                }
            }
        }
        if (node[i] != -1) node[i]--;
    }
    // printf("\n\n");
}

void calculate() {
    float a = (float)((FREQUENCY1 * FREQUENCY2) - FREQUENCY1 - FREQUENCY2 + 1) /
              (FREQUENCY1 * FREQUENCY2);
    float b = (float)(a * 2);
    /*printf("There is %d nodes.\n", node_num);
    printf(
        "Averagely,the probability of asking for channel is %.5f for each node "
        "every second.\n",
        a / node_num);
    printf("Every node need 1~3 second to send it`s information.\n");
    printf(
        "So averagely,there will create %.5f second information every "
        "second.\n",
        b);
    printf("Finally,the utilization rate of channel is %.5f", (1 - (hhh /
    hh)));*/
    use = 1 - (hhh / hh);
}

int main() {
    for (int l = 0; l < CI; l++) {
        t_time = 0;
        // srand(time(NULL));
        t_node = -1;
        hh = 0;
        hhh = 0;
        nooo = 0;
        memset(node, -1, sizeof(node));
        memset(delay_node, -1, sizeof(delay_node));
        memset(ask, -1, sizeof(ask));
        // printf("ask[19]=%d\n", ask[19]);
        // printf("delay_node[MAX_delay_ndoe]=%d\n",
        // delay_node[MAX_delay_ndoe-1]);

        while (1) {
            // printf("%d second:\n", hh);
            hh++;
            if (t_node == -1) hhh++;
            //随机生成asking node（0~MAX_ASK）
            asking();
            //使用信道
            using();
            //节点状态调整和打印
            node_op();
            if (hh == TIME) {
                for (int i = 0; i < node_num; i++) {
                    if (node[i] != -1) {
                        // printf("%d:%d \n", i, node[i]);
                        nooo++;
                    }
                }
                calculate();
                // printf("\nnooo:%d", nooo);
                break;
            }
            // sleep(1);
        }
        total = total + use;
        nto += nooo;
        // printf("111");
    }
    printf("%.5f,nooo:%.2f", total / CI, nto / CI);
    return 0;
}