#include <iostream>
#include <map>

using namespace std;

/*
 * 设计一种结构, 该结构有如下三个功能:
 *      insert(key): 将某个key加入到该结构, 做到不重复加入
 *      delete(key): 将原本在结构中的某个key移除
 *      getRandom(): 等概率随机返回结构中的任何一个key
 * */

class LookupTable
{
private:
    int size;
    map<string, int> keyIndexMap;
    map<int, string> indexKeyMap;

public:
    LookupTable()
    {
        size = 0;
    }

    void insert(string key)
    {
        size++;
        keyIndexMap[key] = size;
        indexKeyMap[size] = key;
    }

    void del(string key)
    {
        int index = keyIndexMap[key];
        string lastKey = indexKeyMap[size];
        size--;

        keyIndexMap[lastKey] = index;
        indexKeyMap[index] = lastKey;
    }

    string getRandom()
    {
        srand((int) time(NULL));
        int index = rand() % size + 1;
        string key = indexKeyMap[index];

        return key;
    }

};

int main()
{
    LookupTable table;
    table.insert("zhangsan");
    table.insert("lisi");
    table.insert("wangwu");

    cout << table.getRandom() << endl;

    return 0;
}