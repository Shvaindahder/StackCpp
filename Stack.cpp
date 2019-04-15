#include "Stack.hpp"
#include <vector>

using namespace std;

Stack::Stack(int s): size(s) {
    Elem* prev = nullptr;
    for(int i = 0; i < s; i++) {
        prev = new Elem();
        if(top != nullptr) {
            prev->next = top;
            top = prev;
        }
        else {
            top = prev;
            top->next = nullptr;
        }
    }
}

Stack::Stack(const Stack* stack): size(stack->getSize()) {
    top = new Elem();
    Elem* copyStackTop = stack->getTopElem();
    top->current = copyStackTop->current;
    Elem* prev = top;
    while(copyStackTop->next) {
        Elem* temp = new Elem();
        prev->next = temp;
        copyStackTop = copyStackTop->next;
        temp->current = copyStackTop->current;
        prev = temp;
    }
}

Stack::~Stack() {
    while(top->next) {
        Elem* temp = top;
        top = top->next;
        delete temp;
    }
    delete top;
}

void Stack::push(int num) {
    size += 1;
    Elem* temp = new Elem();
    temp->current = num;
    temp->next = top;
    top = temp;
}

int Stack::pop() {
    size -= 1;
    Elem* temp = top;
    top = temp->next;
    int num = temp->current;
    delete temp;
    return num;
}

void Stack::printStack() {
    Elem* temp = top;
    while(temp->next) {
        cout<<"|    "<<temp->current<<endl;
        temp = temp->next;
    }
    cout<<"|    "<<temp->current<<endl;
}

int Stack::getMaxElement() {
    Elem* temp = top;
    int max = temp->current;
    do {
        temp = temp->next;
        if(temp->current > max) {
            max = temp->current;
        }
    } while (temp->next);
    return max;
}

void Stack::sort() {
    /*
     [3, 1, 6, 2, 6, 8, 1, 7, 5, 0, 4]
     [0, 0, 0, 0, 0, 0, 0, 0, 0]
     [1, 2, 1, 1, 1, 1, 2, 1, 1]
     [0, 1, 1, 2, 3, 4, 5, 6, 6, 7, 8]
     */
    int maxElement = getMaxElement() + 1;
    vector<int> c(maxElement, 0);
    cout<<endl;
    Elem* temp = top;
    while (temp->next) {
        c[temp->current] += 1;
        temp = temp->next;
    }
    cout<<endl;
    c[temp->current] += 1;
    temp = top;
    for(int i = 0; i < maxElement; i++) {
        for(int j = 0; j < c[i]; j++) {
            temp->current = i;
            temp = temp->next;
        }
    }
}
