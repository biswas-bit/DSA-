# include<iostream>
using namespace std;
double power(double x, int n)
{
    long binaryForm=n;
    if(n==0) return 1.0;  // if power is 0 returns 1
    if(x==0) return 0.0;   // if base is  returns 0
    if(x==1) return 1.0;    // if base is 1 returns 1
    if(x==-1 && n%2==0) return 1.0;  /* if base is negative and even  returns 1 */
    if(x==-1 && n%2!=0) return -1.0;  /* if  base is negative and odd returns -1  */
    if(n<0)   // handles negative sign
    {
        x=1/x;                     
        binaryForm = -binaryForm;
    }
    double ans=1;
    while(binaryForm>0)
    {
        if(binaryForm %2 ==1)  // if last digit is one
        {
            ans*=x;       
        }
        x*=x;
        binaryForm /=2;
    }
    return ans;
    
}
int main()
{
    int cal=power(2,2);
    cout<<cal<<endl;
    return 0;
}
