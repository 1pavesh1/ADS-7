// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
#include <utility>

struct SYM {
    char ch;
    int prior;
};

bool PredicForMyList(const SYM &value1, const SYM &value2) {
    return value1.prior > value2.prior;
}

template<typename T>
class TPQueue {
private:
    std::list <T> myList;
    int head;

public:
    TPQueue() {
        head = -1;
    }
    void push(T value) {
        if (head == -1) {
            myList.push_front(value);
            head += 1;
        } else {
            myList.push_front(value);
            myList.sort(PredicForMyList);
            head += 1;
        }
    }
    bool empty() {
        return head == -1;
    }
    T top() {
        return myList.front();
    }
    T pop() {
        head -= 1;
        auto element = myList.front();
        myList.pop_front();
        return element;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
