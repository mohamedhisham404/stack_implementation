#include<iostream>
#include<string>
using namespace std;

class stack
{
private:
    int arr[5];
    int top;

public:

    stack()
    {
        top =0;
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
            cout<<popValue;
            return popValue;
            

        }
    }
};

class Postfix:public stack
{
public:    
    int PostFix()
    {
        int num = 0;
	    char expression[50];
	    stack myStack;
	
	    cout << "***************** Postfix Expression Calculator *****************" << endl;
	    cout << "Separate using spaces." << endl;
	    cout << "Enter your Expression: ";
	
	    cin.getline(expression, 50, '\n');
	
	    for(int i = 0; i < 50 && expression[i] != '\0'; i++) 
        {
            // if the character is a number
		    if (expression[i] >= '0' && expression[i] <= '9') 
            { 	
			    do 
                { 	
                    // Conversion to int											
				    num = num*10;
				    num += (expression[i] - '0');
				    i++;
			    } 
                while(expression[i] != ' ');

		    	// Now integer num has an operand
			    myStack.push(num);
			    num = 0;
		    }
		    else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
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
    Postfix Postfix1;

    //stack1.push(5);
    //stack1.pop();

    Postfix1.PostFix();

    return 0;
} 