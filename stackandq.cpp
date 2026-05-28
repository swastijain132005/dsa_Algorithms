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
