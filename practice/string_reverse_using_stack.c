#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char Name[50];
char Name2[50];
int top = -1;
// void reverse(int index)
// {
//     int i;
//     for (i = 0; i < (int)(index/2); i++)
//     {
//         char temp = Name[i];
//         Name[i] = Name[index - i];
//         Name[index - i] = temp;
//     }
// }
void reverse(int index)
{
    int i;
    char temp;
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        for (i = 0; i <= (index); i++)
        {
            Name2[i] = Name[index - i];
            top--;
        }
        for (i = 0; i <= (index); i++)
        {
            temp=Name2[i];
            Name[i] = temp;
            top++;
        }
    }
}
int main()
{
    printf("Enter string:");
    fgets(Name, 50, stdin);
    int index = strlen(Name) - 1;
    top = index;
    reverse(index);
    printf("reverse string:%s", Name);
    return 0;
}