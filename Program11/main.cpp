//  Program11Stack
//  Created by Minjing Liang on 11/6/20.
#include <iostream>
#include <string>
using namespace std;
template <class T>
class StaticStack{
private:
    int top;
    int stackSize;
    T *stackArray;
public:
    //constructor
    StaticStack(int s){
        stackSize = s;   //set size
        top = -1;//set top to -1 to indicate empty stack
        stackArray = new T[s];     //create array with input size
    }
    StaticStack(const StaticStack&obj){  // copy constructor
        if(obj.stackSize > 0)  //create the stack array
            stackArray = new T[obj.stackSize];
        else
            stackArray = nullptr;
        stackSize = obj.stackSize; // copy the stackSize attibute
        for(int i = 0; i < stackSize; i++) //copy contents
        stackArray[i] = obj.stackArray[i];
        top = obj.top; // set the top of the stack
    }
    void push(T val){   //push function
        if(isFull()){//first check if stack is full
            cout << "Stack is full.\n";
        }
        else{
            top++; //increment top to point to next element
            stackArray[top] = val; //store value in position top
        }
    }
    void pop(T &var){        //pop function
        if(isEmpty()){ //first check if stack is empty
            cout << "Stack is empty!\n";
        }
        else{
            top--;//decrement top
            var = stackArray[top + 1]; //store value that top pointed
        }
    }
    bool isFull(){   //function that check whether stack is full or not
        if(top == stackSize - 1)
            return true;
        return false;
    }
    bool isEmpty(){   //function that check whether stack is empty or not
        if(top == -1)
            return true;
        return false;
    }
    ~StaticStack(){ //destructor
        if(stackSize > 0)
        delete [] stackArray;
    }
};
template <class T>
class DynamicStack{
private:
    //struct for Nodes of dynamic stack
    struct Node{
        T value;//to hold value of Node
        Node *next;//to point to next Node
    };
    Node *top;//pointer to top of stack
public:
    DynamicStack(){  //constructor
        top = nullptr;//set top pointer to null
    }
    void push(T val){   //push function
        Node *newNode = nullptr; //Pointer to a new node
        newNode = new Node; // Allocate a new node and store num there
        newNode->value = val;
        if(isEmpty()){  // check if stack is empty
                top = newNode;
                newNode->next = nullptr;
            }
            else{  // insert newNode before top
                newNode->next = top;
                top = newNode;
            }
    }
    void pop(T &val){  //pop function
        Node *temp =nullptr;
        if(isEmpty()){  //first check if stack is empty
            cout << "Stack is empty!\n";
        }
        else{ //Pop value off top of stack
            val = top->value;
            temp = top->next;
            delete top;
            top = temp;
        }
    }
    bool isEmpty(){ //Check if the stack is empty or not
        if(!top)
            return true;
        else
        return false;
    }
    ~DynamicStack(){ //destructor
        Node *currentNode = top; //Pointer position at the top of the stack
        Node *nextNode;
        while(currentNode != nullptr){ //Traverse the list and delete each node
            nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }
};
int main()
{
    cout << "Create a stack of strings with size 3\n";
    StaticStack<string> sS(3); //A string static stack obj
    cout << "Push Anne onto stack.\n";
    sS.push("Anne"); //Call push function add element
    cout << "Push Mike onto stack.\n";
    sS.push("Mike");
    cout << "Push Kyle onto stack.\n";
    sS.push("Kyle");
    cout << "Now try to push another value onto stack.\n";
    sS.push("Jack"); //Push element to a full stack
    cout << "Retrieve elements one by one till the stack is empty.\n";
    string retrieved;
    while(!sS.isEmpty()){ //Pop all the elements out of the stack
        cout << "Retrive top element.\n";
        sS.pop(retrieved);
        cout << "It is: " << retrieved << endl;
    }
    cout << "Attempt another pop operation.\n";
    sS.pop(retrieved); //Pop element from empty stack
    cout << "\nNow,create a stack of integers.\n";
       DynamicStack<int> dS;//An integer dynamic stack obj
       cout << "Push 21 onto stack.\n";
       dS.push(21); //Call push function
       cout << "Push 35 onto stack.\n";
       dS.push(35);
       cout << "Push 8 onto stack.\n";
       dS.push(8);
       cout << "Retrieve elements one by one till the stack is empty.\n";
       int value;
       while(!dS.isEmpty()){ //Pop out all elements from the stack
           cout << "Retrieving top element.\n";
          dS.pop(value);
           cout << "It is: " << value << endl;
       }
       //attempt to pop again
       cout << "Attempt another pop operation.\n";
       dS.pop(value);
    return 0;
}
