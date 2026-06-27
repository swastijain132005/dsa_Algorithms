Stacks and Queues
Implement stack using array
class myStack {
    int *arr;
    int size;
    int top;
  public:
    myStack(int n) {
        // Define Data Structures
        size=n;
        top=-1;
        arr=new int[n];
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==-1;
    }

    bool isFull() {
        // check if the stack is full
        return top==size-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
         if (top < size - 1) {
            arr[++top] = x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if (top >= 0) {
            top--;
        }
    }

    int peek() {
        // Returns the top element of the stack
if (top >= 0)
            return arr[top];
        return -1;    }
};
Implement stack using LinkedIn list

/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
 
    Node *top;
    int sze;
  public:
    myStack() {
        // Initialize your data members
        top=NULL;
        sze=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==NULL;
 
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *temp=new Node(x);
        temp->next=top;
        top=temp;
        sze++;
 
    }

    void pop() {
        // Removes the top element of the stack
         if (top == NULL) return;
        Node *temp = top;
        top = top->next;
        delete temp;
        sze--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
          if (top == NULL) return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sze;
    }
};
Queue using array
class myQueue {
    int front;
    int rear;
    int size;
    int *arr;

  public:
    myQueue(int n) {
        // Define Data Structures
        front=rear=-1;
        size=n;
        arr=new int[n];
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==-1&&rear==-1;
    }

    bool isFull() {
        // check if the queue is full
        return rear==size-1 &&front==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear]=x;

    }

    void dequeue() {
        // Removes the front element of the queue.
        if(front==-1&&rear==-1){
            return;
        }
        if(front==rear){
            front=rear=-1;
        }
        else{
        front++;}
    }

    int getFront() {
        // Returns the front element of the queue.
        if(rear==-1){
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(rear==-1){
            return -1;
        }
 
        return arr[rear];
    }
};
Queue using LinkedIn list
Rear ka next temp
Then rear =temp
Previous smaller element
vector<int> previousSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st; // stores elements

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return pse;
}
Previous greater element
Bas stack.top <=arr[i]
Next smaller element
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(arr[i]);
    }
    return nse;
}
Next greater element

Just st.top<=Arr [i]


    // Next Smaller Element (Right)
        for (int i = rows - 1; i >= 0; i--) {
            int j = cols - 1;

            while (j >= 0) {   // FIX: >= 0
                while (!st1.empty() &&
                       height[st1.top().first][st1.top().second] >= height[i][j]) {
                    st1.pop();
                }

                nse[i][j] = st1.empty() ? cols : st1.top().second;
                st1.push({i, j});
                j--;
            }

            while (!st1.empty()) st1.pop(); // clear stack per row
        }

        // Previous Smaller Element (Left)
        for (int i = 0; i < rows; i++) {
            int j = 0;

            while (j < cols) {
                while (!st2.empty() &&
                       height[st2.top().first][st2.top().second] >= height[i][j]) {
                    st2.pop();
                }

                pse[i][j] = st2.empty() ? -1 : st2.top().second;
                st2.push({i, j});
                j++;   // FIX: j++ instead of j--
            }

            while (!st2.empty()) st2.pop(); // FIX: clear correct stack
        }




// Infix to Postfix
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {

    stack<char> st;
    string ans = "";

    for(char ch : s) {

        // Operand
        if(isalnum(ch)) {
            ans += ch;
        }

        // Opening bracket
        else if(ch == '(') {
            st.push(ch);
        }

        // Closing bracket
        else if(ch == ')') {

            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }

        // Operator
        else {

            while(!st.empty() &&
                  st.top() != '(' &&
                  (prec(st.top()) > prec(ch) ||
                  (prec(st.top()) == prec(ch) && ch != '^'))) {

                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {

    string s = "(A-B/C)*(A/K-L)";
    cout << infixToPostfix(s);

    return 0;
}



// Infix to Prefix
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {

    reverse(s.begin(), s.end());

    for(char &ch : s) {
        if(ch == '(')
            ch = ')';
        else if(ch == ')')
            ch = '(';
    }

    stack<char> st;
    string ans = "";

    for(char ch : s) {

        // Operand
        if(isalnum(ch)) {
            ans += ch;
        }

        // Opening bracket
        else if(ch == '(') {
            st.push(ch);
        }

        // Closing bracket
        else if(ch == ')') {

            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }

        // Operator
        else {

            while(!st.empty() &&
                  st.top() != '(' &&
                  (prec(st.top()) > prec(ch) ||
                  (prec(st.top()) == prec(ch) && ch == '^'))) {

                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    string s = "(A-B/C)*(A/K-L)";
    cout << infixToPrefix(s);

    return 0;
}

// Postfix to Infix
// TC: O(n)
// SC: O(n)

Logic
If operand → push into stack.
If operator:
Pop top two strings.
Form (op1 operator op2).
Push back the new expression.
Final stack element is the infix expression.

#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {

    stack<string> st;

    for(char ch : s) {

        // Operand
        if(isalnum(ch)) {
            st.push(string(1, ch));
        }

        // Operator
        else {

            if(st.size() < 2)
                return "Invalid Expression";

            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string exp = "(" + op1 + ch + op2 + ")";

            st.push(exp);
        }
    }

    if(st.size() != 1)
        return "Invalid Expression";

    return st.top();
}

int main() {

    string s = "ABC/-AK/L-*";
    cout << postfixToInfix(s);

    return 0;
}

// Prefix to Infix
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {

    stack<string> st;

    // Traverse from right to left
    for(int i = s.size() - 1; i >= 0; i--) {

        char ch = s[i];

        // Operand
        if(isalnum(ch)) {
            st.push(string(1, ch));
        }

        // Operator
        else {

            if(st.size() < 2)
                return "Invalid Expression";

            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string exp = "(" + op1 + ch + op2 + ")";

            st.push(exp);
        }
    }

    if(st.size() != 1)
        return "Invalid Expression";

    return st.top();
}

int main() {

    string s = "*-A/BC-/AKL";
    cout << prefixToInfix(s);

    return 0;
}


// Postfix to Prefix
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s) {

    stack<string> st;

    for(char ch : s) {

        // Operand
        if(isalnum(ch)) {
            st.push(string(1, ch));
        }

        // Operator
        else {

            if(st.size() < 2)
                return "Invalid Expression";

            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string exp = ch + op1 + op2;

            st.push(exp);
        }
    }

    if(st.size() != 1)
        return "Invalid Expression";

    return st.top();
}

int main() {

    string s = "ABC/-AK/L-*";
    cout << postfixToPrefix(s);

    return 0;
}

// Prefix to Postfix
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s) {

    stack<string> st;

    // Traverse from right to left
    for(int i = s.size() - 1; i >= 0; i--) {

        char ch = s[i];

        // Operand
        if(isalnum(ch)) {
            st.push(string(1, ch));
        }

        // Operator
        else {

            if(st.size() < 2)
                return "Invalid Expression";

            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string exp = op1 + op2 + ch;

            st.push(exp);
        }
    }

    if(st.size() != 1)
        return "Invalid Expression";

    return st.top();
}

int main() {

    string s = "*-A/BC-/AKL";
    cout << prefixToPostfix(s);

    return 0;
}

