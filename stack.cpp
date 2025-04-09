// infix to post fix
# include<iostream>
# include<vector>
using namespace std;

class stack{
    int size;
    int *arr;
    int top;
    public:
    stack(int n)
    {
        size=n;
        arr=new int[size];
        top=-1;
    }
    
    void push(int data)
    {
        if(size==top-1)
        {
            cout<<"this stack is overflow"<<endl;
            return;
        }
        else{
            arr[++top]=data;
        }
    }
    
    void pop()
    {
        if(top==-1)
        {
            cout<<"this stack is empty"<<endl;
            return;
        }
       
        else{
            int popped=arr[top];
            top --;
            cout<<"Popped:" <<popped<<endl;
        }
    }
    
    void display()
    {
         if(top==-1)
        {
            cout<<"this stack is empty"<<endl;
            return;
        }
        else{
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    stack ss(5);
    vector<int>arr={35,36,12,56,34};
    for(int value: arr)
    {
        ss.push(value);
    }
    ss.pop();
    ss.display();
    return 0;
}
