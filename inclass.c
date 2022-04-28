#include <stdio.h>
#include <math.h>

int main()
{
    char op;
    int val = 0;
    int count = 1;
    int tot = 0;
    while(op != '=')
    {
        scanf(" %d",&val);
        scanf(" %c",&op);
        if(op == '=')
            break;
        else if(op == '+')
            tot = tot + val;
        else
            tot = tot - val;
        count++;
    }
    printf("%d\n",tot);
    return 0;
}