#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define NODE 5
#define Delay_Time 5
#define TIME 20000
int node[NODE];
int t_node = -1, hh = 0;
float hhh;

void calculate() {
    printf("There is %d nodes.\n", NODE);
    //printf(
    //    "Averagely,the probability of asking for channel is %.5f for each node "
    //    "every second.\n",
    //    (1 / (float)Delay_Time));
    // printf("Every node need 1 second to send it`s information.\n");
    printf("Finally,the utilization rate of channel is %.5f", 1 - (hhh / hh));
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < NODE; i++) {
        node[i] = rand() % Delay_Time;
    }
    while (1) {
        hh++;
        /*printf("%d second:\n", hh);
        printf("node:\n");
        for (int i = 0; i < NODE; i++) {
            printf("%d:%d\n", i, node[i]);
        }*/
        int n = 0;
        for (int i = 0; i < NODE; i++) {
            if (node[i] != 0) {
                node[i]--;
            } else {
                t_node = i;
                n++;
                node[i] = rand() % Delay_Time;
            }
        }
        if (n != 1) {
            t_node = -1;
            hhh++;
        }
        //printf("now node%d is using\n", t_node);
        //printf("\n");
        if (hh == TIME) {
            calculate();
            break;
        }
    }
    return 0;
}