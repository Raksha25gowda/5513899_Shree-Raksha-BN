#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100000
int arr[MAX];
int size = 0;

void insert(int x) {
    arr[size++] = x;
}

void deleteVal(int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            arr[i] = arr[size - 1];
            size--;
            break;
        }
    }
}

int getMin() {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int v;
            scanf("%d", &v);
            insert(v);
        } 
        else if (type == 2) {
            int v;
            scanf("%d", &v);
            deleteVal(v);
        } 
        else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
