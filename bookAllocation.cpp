#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) 
{
    int stu = 1, pages = 0;
    
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > maxAllowedPages)
        {
            return false;  // A book has more pages than allowed, so it's not possible
        }
        
        if (pages + arr[i] <= maxAllowedPages) 
        {
            pages += arr[i];
        } 
        else 
        {
            stu++;
            pages = arr[i]; // New student takes the book
        }
        
        if (stu > m)
        {
            return false;  // More students needed than available
        }
    }
    
    return true;
}

int allocateBooks(vector<int> &arr, int n, int m) 
{
    if (m > n) 
    {
        return -1; // Not enough books for each student
    }
    
    int sum = 0, maxPages = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];
        maxPages = max(maxPages, arr[i]);
    }

    int ans = -1;
    int start = maxPages, end = sum;  // Start from max(arr) instead of 0

    while (start <= end)                       // main logic
    {
        int mid = start + (end - start) / 2;
        
        if (isValid(arr, n, m, mid)) 
        {
            ans = mid;  // Store the valid answer
            end = mid - 1;  // Try to find a smaller max allocation
        } 
        else 
        {
            start = mid + 1;  // Increase the allowed pages
        }
    }

    return ans;
}

int main() 
{
    vector<int> arr = {2, 1, 3, 4};
    int n = arr.size(), m = 2;
    
    cout << "Minimum maximum pages: " << allocateBooks(arr, n, m) << endl;
    
    return 0;
}

