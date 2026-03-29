#include <stdbool.h>

bool canBeEqual(char* s1, char* s2) {
    int a1[2] = {s1[0], s1[2]};
    int b1[2] = {s2[0], s2[2]};

    int a2[2] = {s1[1], s1[3]};
    int b2[2] = {s2[1], s2[3]};

    if(a1[0] > a1[1]) {int t = a1[0]; a1[0] = a1[1]; a1[1] = t;}
    if(b1[0] > b1[1]) {int t = b1[0]; b1[0] = b1[1]; b1[1] = t;}

    if(a2[0] > a2[1]) {int t = a2[0]; a2[0] = a2[1]; a2[1] = t;}
    if(b2[0] > b2[1]) {int t = b2[0]; b2[0] = b2[1]; b2[1] = t;}

    return (a1[0] == b1[0] && a1[1] == b1[1] && a2[0] == b2[0] && a2[1] == b2[1]);
}

