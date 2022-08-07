//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        map<char,int> m;
        m['(']=0;
        m['+']=m['-']=1;
        m['*']=m['/']=2;
        m['^']=3;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i]))
            cout<<s[i];
            else if(s[i]=='(')
            st.push('(');
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    cout<<st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && m[st.top()]>=m[s[i]])
                {
                    cout<<st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            cout<<st.top();
            st.pop();
        }
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
