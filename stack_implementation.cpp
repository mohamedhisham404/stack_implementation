#include<iostream>
#include<string>
using namespace std;

class stack
{
private:
    int arr[10] ;
    int top = -1;
public:
    stack()
    {
        top = 0;
        for (int i=0; i<10;i++)
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

    
    void display()
    {
        for(int i=9 ; i>0 ; i--)
        {
            cout<<arr[i]<<endl;
        }
    }

    void change(int pos , int val)
    {
            arr[pos] = val;
            cout<<"value changed at location "<<pos<<endl;
    }

    int count()
    {
        cout<<top+1;
        return 0;
    }

};

int main()
{
    stack stack1;
    int option , postion,value;
    do
    {
        cout<<"**********************WELCOME TO STACK**********************"<<endl;
        cout<<"WHAT DO YOU WANT TO DO?"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"1. PUSH"<<endl;
        cout<<"2. POP"<<endl;
        cout<<"3. COUNT"<<endl;
        cout<<"4. CHANGE"<<endl;
        cout<<"5. DISPLAY"<<endl;
        cout<<"6. CLEAR SCREAN"<<endl;
        cout<<"ENTER THE NUMBER NOW,WHAT ARE YOU WAITING FOR?"<<endl;

        cin>>option;

        switch (option)
        {
        case 1:
            cout<<"INTER AN ITEM TO PUSH IN THE STACK"<<endl;
            cin>>value;
            stack1.push(value);
            break;

        case 2:
            cout<<"POP FUNCTION IS CALLED....POPED VALUE IS: "<<stack1.pop()<<endl;
            break;

        case 3:
            cout<<"COUNT FUNCTION CALLED....NUMBER OF ITEMES IN THE STACK IS: " <<stack1.count()<<endl;
            
            break;
        case 4:
            cout<<"CHANGE FUNCTION IS CALLED"<<endl;
            cout<<"ENTER THE POSITION OF ITEM YOU WANT TO CHANGE"<<endl;
            cin>>postion;
            cout<<endl;
            cout<<"ENTER THE VALUE OF ITEM YOU WANT TO CHANGE"<<endl;
            cin>>value;
            stack1.change(postion,value);
            break;

        case 5:
            cout<<"DISPLAY FUNCTION IS CALLED"<<endl;
            stack1.display();
            break;

        case 6:
            system("cls");
            break;

        default:
            cout<<"ENTER PROPER OPTION NUMBER : "<<endl;    
        }
    } while (option != 0);
    
    
    return 0;
}
