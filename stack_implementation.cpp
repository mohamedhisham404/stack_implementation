#include<iostream>
using namespace std;

class stack
{
private:
    int arr[5];
    int top;

public:

    stack()
    {
        top =-1;
        for (int i; i<5;i++)
        {
            arr[i]=0;
            
        }
    }

    bool isEmbty()
    {
        if(top == -1)
        {
            return true;
        }
        else
            return false;
    }    

    bool isFull()
    {
        if(top==5)
        {
            return true;
        }
        else
            return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout<<"stack is overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=val;
            
        }
    }

    int pop()
    {
        if(isEmbty())
        {
            cout<<"stack is underflow"<<endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top]=0;
            top--;
            return popValue;
            

        }
    }
};
int main()
{    
    stack stack1;
    stack1.push(5);
    stack1.pop();
    stack1.pop();


    return 0;
} 