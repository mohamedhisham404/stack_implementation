#include<iostream>
#include<string>
using namespace std;

class stack
{
private:
    int arr[50] ;
    int top = -1;
public:
    stack()
    {
        top = 0;
        for (int i=0; i<50;i++)
        {
            arr[i]=0;
            
        }
    }
    
    bool isEmbty()
    {
        return top == -1;
    }
    
    bool isFull()
    {
        return top == 4;
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

    int PostFix()
    {
        int num = 0;
        char expression[50];
        stack myStack;

        cout << "***************** Postfix Expression Calculator *****************" << endl;
        cout << "Separate using spaces." << endl;
        cout << "Enter your Expression: ";

        cin.getline(expression, 50, '\n');

        for (int i = 0; i < 50 && expression[i] != '\0'; i++)
        {
            // if the character is a number
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                do
                {   
                    // Conversion to int											
                    num = num * 10;
                    num += (expression[i] - '0');
                    i++;
                } 
                while (expression[i] != ' ');

                // Now integer num has an operand
                myStack.push(num);
                num = 0;
            }
        else if (expression[i] == ' ')
            continue;
        else
            {
                int op2 = myStack.pop();
                int op1 = myStack.pop();
                int res;

                switch (expression[i])
                {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }

            myStack.push(res);
        }
    }
    cout << "Result: " << myStack.pop() << endl << endl;

    return 0;
    }
};

int main()
{    
    stack stack1;
    

    //stack1.push(5);
    //stack1.pop();

    stack1.PostFix();

    return 0;
} 
