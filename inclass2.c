#include <stdio.h>
#include <math.h>

int main()
{
    char str[20];
    printf("enter string (no spaces): ");
    scanf("%s",str);
    int i;
    char temp[20];
    int mark = 20;
    for(i = 0; i < 20; i++)
    {
        temp[i] = str[mark];
        mark--;
    }
    if(temp == str)
        printf("palindrome");
    else
        printf("not palindrome");
    
    return 0;
}