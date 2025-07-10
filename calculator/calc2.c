#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (! argc == 4) {
        printf("Wrong combinaison");
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char *op = argv[2];

    if (strcmp(op,"+") == 0) {
        printf("%d\n",a+b);
    }
    else if (strcmp(op,"-") == 0) {
        printf("%d\n",a-b);
    }
    else if (strcmp(op,"x") == 0) {
        printf("%d\n",a*b);
    }
    else if (strcmp(op,"/") == 0) {
        printf("%d\n",a/b);
    } else {
        printf("Wrong operator %s",op);
    }
    return 0;
}