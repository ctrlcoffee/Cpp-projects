#include <iostream>
using namespace std;
#define MAX 1000

class Queue {
private:
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        arr[++rear] = value;
        cout << "Enqueued " << value << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        std::cout << "Dequeued: " << arr[front] << std::endl;
        if (front == rear) {
            front = rear = -1;  // Reset queue after last element is dequeued
        }
        else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
