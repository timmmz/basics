#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    // if too many arguments, print correct way and return 1
    if (!argc == 4){
        printf("Format is incorrect \n");
        return 1;
    }
    // set the variables for the first el, second and third
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char *op = argv[2];

    // check if operator is correct
    if (strcmp(op,"+") == 0) {
        printf("Result = %d\n",a + b);
    } else if (strcmp(op,"-") == 0) {
        printf("Result = %d\n",a - b);
    } else {
        printf("Incorrect operator, please verify");
        return 1;
    }
        // return result


    // print result
    return 0;
}