#include <iostream> 
#include <iomanip> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm>
#include <climits>
#include <set> 
#include <unordered_map> 
#include <unordered_set> 
#include <map> 
#include <cstdio>
#include <stack>
  using namespace std; 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
     int n; 
     cin >> n; 
     vector<int> v(n); 
     for (int i = 0; i < n; i++) cin >> v[i]; 
     stack<int> st; 
     vector<int> ans(v.size(), -1);
      for (int i = 0; i < v.size(); i++) 
      { 
          while (!st.empty() && v[st.top()] < v[i] ) 
            {   
                cout<<"st.top() : "<<st.top()<<"\n";
                ans[st.top()] = v[i]; 
                st.pop(); 
            } st.push(i); 
        } 
        for (int x : ans) cout << x << " "; 
        return 0; 
}