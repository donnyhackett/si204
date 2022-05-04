#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define interleave here!
char* interleave(char*, char*);

int main(){
    char* s1 = "get";
    char* s2 = "ras";
    char* w = interleave(s1,s2);
    printf("%s\n",w);
    free(w);

    return 0;
}

char* interleave(char* one, char* two){
    int i;
    int index = 0;
    char* temp = (char*) malloc(strlen(one)*sizeof(char*));
    for(i = 0; i < strlen(one); i++){
        temp[index] = one[i];
        index++;
        temp[index] = two[i];
        index++;
    }
    return temp;
}