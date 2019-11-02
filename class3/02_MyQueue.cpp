#include <iostream>

using namespace std;

// 用数组实现大小固定的队列

class MyQueue {
public:

    int *queue;
    int maxSize;
    int size;
    int start, end;


    MyQueue(int maxSize) {
        queue = new int[maxSize];
        this->maxSize = maxSize;
        start = 0, end = 0;
        size = 0;
    }

    ~MyQueue() {
        if (NULL != queue) {
            delete[] queue;
            queue = nullptr;
        }
    }

    void push(int num) {
        if (size == maxSize) {
            throw "queue full!";
        }

        queue[end] = num;
        end = end + 1 == maxSize ? 0 : end + 1;
        size++;
    }

    int pop() {
        if (size == 0) {
            throw "queue empty!";
        }

        int res = queue[start];
        start = start + 1 == maxSize ? 0 : start + 1;
        size--;
    }

    int peek() {
        if (size == 0) {
            throw "queue empty!";
        }

        return queue[start];
    }
};

int main() {
    try {
        MyQueue queue(3);
//        queue.peek();
//        queue.pop();
        queue.push(1);
//        cout << queue.peek() << endl;
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.pop();
        cout << queue.peek() << endl;
    } catch (char const *msg) {
        cerr << msg << endl;
    }


    return 0;
}