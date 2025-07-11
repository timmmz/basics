#include <stdio.h>
#include <stdlib.h>


int mystrln(char *str){
    int i = 0;
    while (str[i]!= '\0') {
        i++;
    }
    return i;
}

void mystringcpy(char dest,char *str)
{
    // let's assume there is enough space in destination
    // we loop in str and add in dest
    for (int i = 0;i< mystrln(str);i++){
        dest[i] = str[i]; 
    }
    dest[mystrln(str)] = '\0'
}
 
int mystrcmp(char *str, char *str2)
{
    // i need to get the length of the biggest
    int strLen = mystrln(str);
    int str2Len = mystrln(str2);
    if (strLen != str2Len){
        return strLen - str2Len;
    } else  {
        for (int i = 0;i< strLen;i++){
            int a = str[i];
            int b = str[i];
            if (a > b) {
                return 1;
            } else if (b > a){
                return -1;
            }
        }
        
        return 0;
    }
    // return 0 if equal
    // return 1 if first bigger
    // return -1 if second bigger
}

// a variable has two elements: the value and the adress in memory
// To declare a pointer, we use *pVariable, this will be equal to &variable, 
// to get the value of a pointer, we use again *

char * mystrcat(char *str1,char *str2) 
{
    int lStr1 = mystrln(str1);
    int lStr2 = mystrln(str2);

    char * new_string = malloc(lStr1 + lStr2 +1);
    if (!new_string){
        return NULL;
    }
    for (int i = 0;i<lStr1;i++){
        new_string[i]= str1[i];

    }
    for (int j = 0; j< lStr2; j++){
        new_string[lStr1 + j] = str2[j];
    }
    new_string[lStr1 + lStr2] = '\0';
    return new_string;
}
int main() {

    char * string = "length";
    printf("The length of length is %d\n", mystrln(string));
    int test = 'a';
    printf("The ASCII of a is %d\n", test);
    char *str1 = "hey";
    char *str2 = "hey";
    char *str3 = "heyy";
    char *str4 = "bob";

    printf("cmp str1 and str2 should be 0: %d / cmp str1 and str3 should be neg %d / cmp str3 and str2 should be pos %d\n",mystrcmp(str1,str2),mystrcmp(str1,str3),mystrcmp(str3,str2));
    printf("Let's concatenate bob and marlon %s", mystrcat("bob","marlon")); 
    char dest[30];
    char *str5 = "hello";
    
    printf("%s",)
    return 0;
}