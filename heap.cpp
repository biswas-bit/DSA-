// heap
 # include<iostream>
 using namespace std;
 
 class heap{
     int capacity;
     int size;
     int *arr;
     public:
     heap(int val)
     {   
         capacity=val;
         size=0;
         arr=new int[size];
         arr[0]=-1;
         
     }
     
     ~ heap()
     {
         delete [] arr;
     }
     
     void insert( int data )
     {
         size+=1;
         int index=size;
         arr[index]=data;
         while(index > 1){
             int parent=index/2;
             if(arr[parent]<arr[index])
             {
                 swap(arr[parent],arr[index]);
             }
             else{
                 return;
             }
         }
         
         
     }
     void display()
     {
         for(int i=1;i<= size;i++)
         {
             cout<<arr[i]<<" ";
         }
         cout<<endl;
     }
 };
 
 int main()
 {
     heap hh(5);
     hh.insert(5);
     hh.insert(4);
     hh.insert(3);
     hh.insert(2);
     hh.display();
     return 0;
 }
