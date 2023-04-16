//
// Created by Boody on 4/10/2023.
//
#include <iostream>
#include <algorithm>
#ifndef DATAA2_STACK_H
#define DATAA2_STACK_H

#endif // DATAA2_STACK_H

using namespace std;
template <typename T>
class Stack
{
private:
    int size = 0;
    T *arr;
    int max;

public:
    Stack(int n)
    {
        size = 0;
        arr = new T[n];
        max = n;
    }
    void printtop()
    {
        cout << arr[size - 1] << endl;
    }
    T top()
    {
        return arr[size - 1];
    }
    void pop()
    {
        if (size != 0)
        {
            cout << arr[size - 1] << endl;
            size--;
        }
    }
    void clear()
    {
        size = 0;
    };
    bool isEmpty()
    {
        return (size == 0);
    }
    void push(int x)
    {

        if (size <= max)
        {
            size++;
            arr[size - 1] = x;
        }
        else
        {
            cout << "Stack is Full !";
        }
    }

    int stackSize()
    {
        return size;
    }
};

// function to calculate the precedence of operations
int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
// function to convert the infix to posttix

string infixToPostfix(string s)
{

    Stack<char> st(s.size()); // For stack operations
    string ans = "";          // The final result string

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // If the current character is an operand, add it to our answer string.
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            ans += ch; // Append the current character of string in our answer

        // If the current character of string is an '(', push it to the stack.
        else if (ch == '(')
            st.push('(');

        // If the current character of string is an ')', append the top character to the answer
        // and pop that top character from the stack until an '(' is encountered.
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top(); // Append the top character of stack in our answer
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.isEmpty() && prec(s[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch); // Push the current character of string in stack
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.isEmpty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
int findMaxLen(string str)
{
    Stack<int> st(str.size());
    int n = str.length();
 
    
    
    st.push(-1);
 
    
    int result = 0;
 
   
    for (int i = 0; i < n; i++)
    {
      
        if (str[i] == '(')
            st.push(i);
         
        
        else
        {
           
            if (!st.isEmpty())
            {
                st.pop();
            }
             
            
            if (!st.isEmpty())
                result = max(result, i - st.top());
 
            
            else
                st.push(i);
        }
    }
 
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << infixToPostfix(s);
    return 0;
}