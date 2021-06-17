#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <unistd.h>

#define FREQUENCY1 5
#define FREQUENCY2 4
#define PERIOD 4
#define NODE 5
float hhh = 0;
int ask, ask_num = 0, hh = 0;
int node[NODE];

void calculate() {
    float a = (float)((FREQUENCY1 * FREQUENCY2) - FREQUENCY1 - FREQUENCY2 + 1) /
              (FREQUENCY1 * FREQUENCY2);
    float b = (float)(a * 1);
    printf("There is %d nodes.\n", NODE);
    printf("The period is %d .\n", PERIOD);
    printf(
        "Averagely,the probability of asking for channel is %.5f for each node "
        "every second.\n",
        a / NODE);
    printf("Every node need 1 second to send it`s information.\n");
    printf(
        "So averagely,there will create %.5f second information every "
        "second.\n",
        b);
    printf("Finally,the utilization rate of channel is %.5f", hhh / hh);
}

int main() {
    srand(time(NULL));
    memset(node, 0, sizeof(node));
    while (1) {
        for (int i = 0; i < NODE; i++) {
            for (int s = 0; s < PERIOD; s++) {
                hh++;
                printf("%d second:\n", hh);
                ask_num = 1;
                if (hh % FREQUENCY1 == 0) {
                    ask_num = 0;
                }
                if (hh % FREQUENCY2 == 0) {
                    ask_num = 0;
                }
                if (ask_num == 1) {
                    ask = rand() % NODE;
                    node[ask]++;
                    printf("asking node:node%d \n", ask);
                }
                if (node[i] != 0) {
                    node[i]--;
                    printf("now node%d is using\n", i);
                    hhh++;
                    // printf("hhh:%d\n", hhh);
                }
                printf("waiting nodes:");
                for (int a = 0; a < NODE; a++) {
                    if (node[a] != 0) printf("%d", a);
                }
                printf("\n\n");
            }
        }
        if ((hh / (NODE * PERIOD)) == 10) {
            calculate();
            break;
        }
    }
    return 0;
}