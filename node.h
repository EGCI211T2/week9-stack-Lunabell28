//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa
//

#ifndef node_h
#define node_h

class NODE{
    char data;  // Changed from int to char
    NODE *nextPtr;
public:
    NODE(char);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    char get_value();
};
typedef NODE* NodePtr;


NODE::NODE(char x){
    data=x;
    nextPtr=NULL;
}

NODE* NODE::get_next(){
    return nextPtr;
}

char NODE::get_value(){
    return data;
}

void NODE::set_next(NODE *t){
    nextPtr=t;
}

NODE::~NODE(){
    // Removed cout - no output during deletion
}

#endif