
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;

public:
    void push(char);
    // int pop();
    char pop();
    Stack();
    ~Stack();
    bool isEmpty();
};


void Stack::push(char x){
    NodePtr new_node = new NODE(x);
    if(new_node)
    {
        new_node -> set_next(top); // set next pointer to the top   
        top = new_node;
        size++;
    }
 
         // Left missing for exercises…
    
}

char Stack::pop(){
        NodePtr t=top; // set temporary = top
        char value; 
        value=t->get_value(); // return removed data
    // Left missing part for exercises

        top = top->get_next(); // set top to the next stack
        size--; // reduce size
        delete t; // delete t from the stack
        return value;
	//be careful of the empty stack!!!
    }

Stack::Stack()
{
    //initialize stack
    top = NULL;
    size = 0;

    
}
Stack::~Stack()
{
    //delete all remaning stack (i.e. pop all) 
    while (top != NULL)
    {
        pop();
    }
}

bool Stack::isEmpty() 
{
    return (top == NULL);
}


#endif