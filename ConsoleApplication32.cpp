#include <iostream>

template <int Size>
class StaticCharStack {
private:
    char stack[Size];
    int top;

public:
    StaticCharStack() : top(-1) {}

    void push(char c) {
        if (top < Size - 1) {
            stack[++top] = c;
        }
        else {
            std::cout << "Stack overflow!" << std::endl;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return stack[top--];
        }
        else {
            std::cout << "Stack underflow!" << std::endl;
            return '\0';
        }
    }

    int size() const {
        return top + 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == Size - 1;
    }

    void clear() {
        top = -1;
    }

    char peek() const {
        if (!isEmpty()) {
            return stack[top];
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
            return '\0';
        }
    }
};

class DynamicCharStack {
private:
    char* stack;
    int capacity;
    int top;

public:
    DynamicCharStack(int initialCapacity = 10) : capacity(initialCapacity), top(-1) {
        stack = new char[capacity];
    }

    ~DynamicCharStack() {
        delete[] stack;
    }

    void push(char c) {
        if (top < capacity - 1) {
            stack[++top] = c;
        }
        else {
            capacity *= 2;
            char* newStack = new char[capacity];
            for (int i = 0; i <= top; ++i) {
                newStack[i] = stack[i];
            }
            delete[] stack;
            stack = newStack;
            stack[++top] = c;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return stack[top--];
        }
        else {
            std::cout << "Stack underflow!" << std::endl;
            return '\0';
        }
    }

    int size() const {
        return top + 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void clear() {
        top = -1;
    }

    char peek() const {
        if (!isEmpty()) {
            return stack[top];
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
            return '\0';
        }
    }
};

int main() {
    StaticCharStack<5> staticStack;
    staticStack.push('A');
    staticStack.push('B');
    staticStack.push('C');

    std::cout << "Static Stack Size: " << staticStack.size() << std::endl;
    std::cout << "Top Element: " << staticStack.peek() << std::endl;

    while (!staticStack.isEmpty()) {
        std::cout << "Popped: " << staticStack.pop() << std::endl;
    }

    std::cout << "Static Stack is Empty: " << (staticStack.isEmpty() ? "true" : "false") << std::endl;

    DynamicCharStack dynamicStack;
    dynamicStack.push('X');
    dynamicStack.push('Y');
    dynamicStack.push('Z');

    std::cout << "Dynamic Stack Size: " << dynamicStack.size() << std::endl;
    std::cout << "Top Element: " << dynamicStack.peek() << std::endl;

    while (!dynamicStack.isEmpty()) {
        std::cout << "Popped: " << dynamicStack.pop() << std::endl;
    }

    std::cout << "Dynamic Stack is Empty: " << (dynamicStack.isEmpty() ? "true" : "false") << std::endl;

    return 0;
}
