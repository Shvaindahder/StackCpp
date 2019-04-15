//
//  Stack.hpp
//  stack
//
//  Created by Vagyrshan on 14.04.2019.
//  Copyright © 2019 Vagyrshan. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>

struct Elem {
    int current;
    Elem* next;
};

class Stack {
    int size;
    Elem* top = nullptr;
    int getMaxElement();
    Elem* getTopElem() const {
        return top;
    }
public:
    Stack(int);
    Stack(const Stack*);
    void push(int);
    int pop();
    int getSize() const {
        return size;
    }
    void sort();
    void printStack();
    ~Stack();
};
#endif /* Stack_hpp */
