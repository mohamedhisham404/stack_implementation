#include<iostream>
#include<string>
using namespace std;

class stack
{
private:
    int arr[10] ;
    int top = -1;
public:
   
    bool isEmbty()
    {
        return top == -1;
    }
    
    bool isFull()
    {
        return top == 10;
    }

    void push(int val)
    {
        if (isFull())
            cout << "stack is overflow" << endl;
        else
            arr[++top] = val;
    }

    int pop()
    {
        if (isEmbty())
        {
            cout << "stack is underflow" << endl;
            return -1;
        }
        else
            return arr[top--];
    }

    bool isBalanced(string expr) 
    {
        stack s;
        char ch;
        for (int i=0; i<expr.length(); i++) 
        {    
            if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
            {    
                s.push(expr[i]);
                continue;
            }
            if (s.isEmbty())    
                return false;
                switch (expr[i]) 
                {
                    case ')':    
                    s.pop();
                    if (ch=='{' || ch=='[')
                        return false;
                    break;
                    
                    case '}': 
                    s.pop();
                    if (ch=='(' || ch=='[')
                        return false;
                    break;
                    
                    case ']': 
                    s.pop();
                    if (ch =='(' || ch == '{')
                        return false;
                    break;
                }
            }
            return (s.isEmbty()); 
}


};

int main()
{
    stack stack1;
    string expr;
    do
    {
        cout<<"ENTER THE EXPRESSION:"<<endl;
        cin>>expr;
        stack1.isBalanced(expr);
        if (stack1.isBalanced(expr))
            cout << "Balanced"<<endl;
        else
            cout << "Not Balanced"<<endl;
    } while (expr != "0");
    
    
    return 0;
}
