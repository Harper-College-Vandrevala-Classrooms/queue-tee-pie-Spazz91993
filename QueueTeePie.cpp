#include <iostream>
#include <string>
using namespace std;

class Cutie {
public:
    virtual string description() = 0;
    virtual int cuteness_rating() = 0;
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A super cute husky puppy.";
    }
    int cuteness_rating() override {
        return 10;
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "An unrealistically cute orange kitty.";
    }
    int cuteness_rating() override {
        return 9;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A pygmy marmoset.. whatever that is.";
    }
    int cuteness_rating() override {
        return 3;
    }
};

template <typename T>
class QueueTees {
private:
    static const int MAX_SIZE = 10;
    T* arr[MAX_SIZE];
    T** top;
    T** start;
public:
    QueueTees() {
        top = arr;
        start = arr;
    }
    bool is_empty() {
        return (top == start);
    }
    bool is_full() {
        return (arr + MAX_SIZE == top);
    }
    void enqueue(T* element) {
        if (!is_full()) {
            *top = element;
            top++;
        }
        else {
            cout << "Queue is full! Can't add more cuties.\n";
        }
    }
    void dequeue() {
        if (!is_empty()) {
            T* poppedElement = *start;
            cout << "Dequeued Cutie: " << poppedElement->description()
                << " with a cuteness rating of " << poppedElement->cuteness_rating() << "\n";
            start++;
        }
        else {
            cout << "Queue is empty! Can't do that.\n";
        }
    }
    int size() {
        cout << "Queue size: " << static_cast<int>(top - start) << "\n";
        return static_cast<int>(top - start);
    }
};

int main() {
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;
    QueueTees<Cutie> queue;
    queue.size();
    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    queue.enqueue(&marmoset);
    queue.size();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.size();
    return 0;
}
