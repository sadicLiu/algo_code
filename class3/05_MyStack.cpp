#include <iostream>
#include <queue>

using namespace std;

// 用两个队列实现栈结构

class MyStack {
private:
    queue<int> data;
    queue<int> help;

public:
    void push(int num) {
        data.push(num);
    }

    int pop() {
        if (data.size() == 0)
            throw "stack empty";

        while (data.size() > 1) {
            help.push(data.front());
            data.pop();
        }

        int res = data.front();
        data.pop();
        queue<int> tmp = data;
        data = help;
        help = tmp;

        return res;
    }

};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(3);
    stack.push(5);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}
