#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int Q;
scanf("%d", &Q);

char *S = malloc(2000000);
int len = 0;

char **history = malloc(Q * sizeof(char*));
int *hist_len = malloc(Q * sizeof(int));
int hist_top = 0;

for (int i = 0; i < Q; i++) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
        char temp[1000001];
        scanf("%s", temp);
        history[hist_top] = malloc(len + 1);
        memcpy(history[hist_top], S, len);
        history[hist_top][len] = '\0';
        hist_len[hist_top++] = len;
        int tlen = strlen(temp);
        memcpy(S + len, temp, tlen);
        len += tlen;
        S[len] = '\0';
    } 
    else if (type == 2) {
        int k;
        scanf("%d", &k);
        history[hist_top] = malloc(len + 1);
        memcpy(history[hist_top], S, len);
        history[hist_top][len] = '\0';
        hist_len[hist_top++] = len;
        len -= k;
        S[len] = '\0';
    } 
    else if (type == 3) {
        int k;
        scanf("%d", &k);
        printf("%c\n", S[k - 1]);
    } 
    else if (type == 4) {
        hist_top--;
        len = hist_len[hist_top];
        memcpy(S, history[hist_top], len);
        S[len] = '\0';
        free(history[hist_top]);
    }
}

for (int i = 0; i < hist_top; i++) free(history[i]);
free(history);
free(hist_len);
free(S);
  
    return 0;
}
