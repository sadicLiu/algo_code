#include <iostream>
#include <stack>

using namespace std;

// 用两个栈实现队列结构

class MyQueue {
private:
    stack<int> data;
    stack<int> help;

public:
    void push(int num) {
        data.push(num);
    }

    int pop() {
        if (data.size() == 0)
            throw "queue empty";

        while (data.size() > 1) {
            help.push(data.top());
            data.pop();
        }
        int res = data.top();
        data.pop();

        while (help.size() > 0) {
            data.push(help.top());
            help.pop();
        }

        return res;
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;

    return 0;
}
