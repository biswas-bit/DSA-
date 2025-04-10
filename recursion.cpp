
# include<iostream>
using namespace std;

int fact(int n){
    if(n==0 || n==1 ) return 1;
    return n*fact(n-1);
}
int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}

void towerOfHanoi(int n, char source, char helper, char destination) {
    if (n == 0) return;
    towerOfHanoi(n - 1, source, destination, helper);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, helper, source, destination);
}

 int gcd(int a, int b) {
    if (b == 0)
        return a; 
    return gcd(b, a % b); 
}

int main(){
    cout<<"factorial:"<<fact(4)<<endl;
    cout<<"fibonacci:"<<fibo(4)<<endl;
    cout<<" "<<endl;
    cout<<"Tower of Honoi"<<endl;
    towerOfHanoi(3, 'A', 'B', 'C');
    cout<<" "<<endl;
    cout<<"gcd of 12 and 14"<<endl;
    cout<<gcd(12,14)<<endl;
    
   
    
    
    return 0;
}
