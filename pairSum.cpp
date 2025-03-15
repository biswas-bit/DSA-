#include<iostream>
#include<vector>
using namespace std;

// Brute force approach
void maxSum(vector<int> vec, int target)
{
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = i + 1; j < vec.size(); j++)
        {
            if(vec[i] + vec[j] == target)
            {
                cout << vec[i] << " " << vec[j] << endl;
            }
        }
    }
}

// Optimized two-pointer approach
vector<int> pairSum(vector<int> vec, int target)
{
    vector<int> ans;
    int i = 0, j = vec.size() - 1;
    while(i < j)
    {
        int ps = vec[i] + vec[j]; 
        if(ps > target)
        {
            j--;
        }
        else if(ps < target)
        {
            i++;
        }
        else
        {
            return {i, j};  // Return indices directly
        }
    }
    return {}; // Return an empty vector if no pair found
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    maxSum(arr, 9);
    vector<int> ans = pairSum(arr, 9);
    
    if(!ans.empty())  
    {
        cout << ans[0] << "," << ans[1] << endl;
    }
    else
    {
        cout << "No valid pair found" << endl;
    }

    return 0;
}
