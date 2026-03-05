#ifndef stack_h
#define stack_h
#include "node.h"
#include <iostream>
using namespace std;

class Stack {
    NodePtr top;
    int size;
public:
    void push(char);
    char pop();
    Stack();
    ~Stack();
    bool isEmpty();
};

void Stack::push(char x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        new_node->set_next(top);
        top = new_node;
        size++;
    }
}

char Stack::pop(){
    if(isEmpty()){
        return '\0';  // Return null character if stack is empty
    }
    NodePtr t = top;
    char value = t->get_value();
    top = t->get_next();
    size--;
    cout << value;  // Print the value during pop
    delete t;
    return value;
}

Stack::Stack(){
    top = NULL;
    size = 0;
}

Stack::~Stack(){
    while(!isEmpty()){
        pop();
    }
}

bool Stack::isEmpty(){
    return top == NULL;
}

#endif