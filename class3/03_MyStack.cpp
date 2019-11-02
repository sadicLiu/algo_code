#include <iostream>

using namespace std;

// 用数组实现大小固定的栈

class MyStack {
public:
    MyStack(int maxSize) {
        this->maxSize = maxSize;
        stack = new int[maxSize];
        index = -1;
    }

    ~MyStack() {
        if (NULL != stack) {
            delete[] stack;
        }
    }

    void push(int num) {
        if (index == maxSize - 1) {
            throw "stack full!";
        }

        stack[++index] = num;
    }

    void pop() {
        if (index == -1) {
            throw "stack empty!";
        }

        index--;
    }

    int peek() {
        if (index == -1) {
            throw "stack empty!";
        }

        return stack[index];

    }

private:
    int index;
    int maxSize;
    int *stack;
};

int main() {

    MyStack stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(34);

    cout << stack.peek() << endl;
    stack.pop();
    cout << stack.peek() << endl;

    return 0;
}