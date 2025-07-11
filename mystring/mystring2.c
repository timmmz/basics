#include <stdio.h>
#include <stdlib.h>

int ln(char *str)
{
    int i = 0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
}

int cmp(char *str1, char *str2)
{
    int l1 = ln(str1);
    int l2 = ln(str2);
    if (l1 == l2){
        for (int i = 0; i<l1;i++){
            int a = str1[i];
            int b = str2[i];
            if (a != b){
                return a - b ;
            }
        }
        return 0;
    }

    return l1-l2;
}

char *cat(char *str1,char *str2)
{
    int l1 = ln(str1);
    int l2 = ln(str2);

    char * ns = malloc(l1 + l2 + 1);
    if (!ns){
        return NULL;
    }
    for (int i = 0; i<l1;i++){
        ns[i]= str1[i];
    }
    for (int k = 0; k < l2; k++){
        ns[l1 + k] = str2[k];
    }
    ns[l1+l2] = '\0';

    return ns;
}

void cpy(char *dest, char *src)
{
    int ls = ln(src);

    for (int i = 0; i<ls;i++){
        dest[i] = src[i];
    }
    dest[ls] = '\0';
}


int main()
{
    char *str1 = "Bob";
    char *str2 = "Bob";
    char *str3 = "William";

    char dest[30];
    cpy(dest,str3);
    printf("%s\n",dest);

    printf("String 1 and 2 are : %d\n",cmp(str1,str2));
    printf("String 1 is %d caracter long\n",ln(str1));

    printf("this is cat %s\n",cat(str2,str3));
    return 0;
}