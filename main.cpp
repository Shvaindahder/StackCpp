//
//  main.cpp
//  stack
//
//  Created by Vagyrshan on 14.04.2019.
//  Copyright © 2019 Vagyrshan. All rights reserved.
//

#include <iostream>
#include "Stack.cpp"

int main(int argc, const char * argv[]) {
    Stack stack(0);
    stack.push((4));
    stack.push(13);
    stack.push(1);
    stack.push(8);
    stack.push(2);
    stack.push(7);
    stack.push(3);
    stack.push(3);
    stack.push(4);
    stack.push(10);
    stack.push(0);
    stack.push(5);
    stack.push(4);
    stack.printStack();
    cout<<endl;
    Stack stack1 = stack;
    stack1.printStack();
    stack.sort();
    cout<<endl;
    stack.printStack();
    cout<<endl;
    stack1.printStack();
    return 0;
}
