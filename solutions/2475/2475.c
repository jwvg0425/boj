#include <stdio.h>
 
 
int main()
{
    int input;
    int i;
    int validate=0;
 
    for(i=0;i<5;i++)
    {
        scanf("%d",&input);
        validate+=input*input;
    }
    printf("%d",validate%10);
    return 0;
}