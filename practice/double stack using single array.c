#include <stdio.h>
int top1 = -1;
int top2 = 10;
int n = 10;
int arr[10];
void push1(int data)
{
    if (top1 == top2 - 1)
    {
        printf("overflow");
    }
    else
    {
        top1++;
        arr[top1] = data;
    }
}
void push2(int data)
{
    if (top2 == top1 + 1)
    {
        printf("overflow");
    }
    else
    {
        top2--;
        arr[top2] = data;
    }
}
int pop1()
{
    if (top1 == -1)
    {
        printf("Stack1 is Underflow");
    }
    else
    {
        int temp = arr[top1];
        top1--;
        return temp;
    }
}
int pop2()
{
    if (top2 == n)
    {
        printf("Stack2 is Underflow");
    }
    else
    {
        int temp = arr[top2];
        top2++;
        return temp;
    }
}
void peek()
{
    if (top1 ==-1)
    {
        printf("Stack 1 is underflow\t");
    }
    else
    {
        printf("top element in stack1 is :%d\t", arr[top1]);
    }
    if (top2 ==n)
    {
        printf("Stack 2 is underflow\n");
    }
    else
    {
        printf("top element in stack2 is :%d\n", arr[top2]);
    }
}
void show()
{
    if (top1 ==-1)
    {
        printf("Stack 1 is underflow\t");
    }
    else
    {
        printf("\nstack1:");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
    if (top2 ==n)
    {
        printf("Stack 2 is underflow\n");
    }
    else
    {
        printf("stack2:");
        for (int i = n - 1; i >= top2; i--)
        {
            printf("%d\t", arr[i]);
        }
    }
}
int main()
{
    push1(10);
    push1(20);
    push2(30);
    push2(40);
    show();
    pop1();
    pop2();
    show();
  return 0;
}
