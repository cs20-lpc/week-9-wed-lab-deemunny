#include <iostream>
#include <string>
#include "ArrayQueue.hpp"

using namespace std;

int main() {

    cout << "front: error, queue is empty, cannot access the front back: error, queue is empty, cannot access the back queue A length: 1 queue A front: -5 queue A back: -5 queue A length: 0 front: error, queue is empty, cannot access the front back: error, queue is empty, cannot access the back queue A is full! queue A length: 10 queue A front: 0 queue A back: 9 queue A contains: 0 1 2 3 4 5 6 7 8 9  queue A is now empty queue B length: 10 queue B front: 0 queue B back: 9 queue B is now empty queue C length: 10 queue C front: 0 queue C back: 9";

    ArrayQueue<int> queue1(3);

    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);

    cout << "Q1: ";
    queue1.printQueue();

    cout << "Q1 Front: " << queue1.front() << endl;
    cout << "Q1 Back: " << queue1.back() << endl;

    queue1.dequeue();
    cout << "Q1 dequeue: ";
    queue1.printQueue();
    
    ArrayQueue<int> queue2(3);

    queue2.enqueue(1);
    queue2.enqueue(2);
    queue2.enqueue(3);

    cout << "Q2 ";
    queue2.printQueue();

    queue2.dequeue();
    queue2.enqueue(4); // should wrap around

    cout << "Q2 wrap around";
    queue2.printQueue();

    ArrayQueue<int> q3(2);

    q3.enqueue(5);
    q3.enqueue(6);
    cout << "Q3: ";
    q3.printQueue();

    q3.enqueue(7); // triggers resize
    q3.enqueue(8);

    cout << "Q3 bigger: ";
    q3.printQueue();

    cout << "Length: " << q3.getLength() << endl;
    cout << "MaxSize: " << q3.getMaxSize() << endl;

    ArrayQueue<int> q4(2);

    cout << "Q4 is empty, trying to break things" << endl;
    try {
        q4.dequeue();
    } catch (string& e) {
        cout << "Caught exception (dequeue): " << e << endl;
    }

    try {
        q4.front();
    } catch (string& e) {
        cout << "Caught exception (front): " << e << endl;
    }

    try {
        q4.back();
    } catch (string& e) {
        cout << "Caught exception (back): " << e << endl;
    }

    ArrayQueue<int> q5(3);
    q5.enqueue(100);
    q5.enqueue(200);
    q5.enqueue(300);

    ArrayQueue<int> q5clone(q5);

    cout << "Original Q5: ";
    q5.printQueue();

    cout << "Q5 clone: ";
    q5clone.printQueue();

    ArrayQueue<int> q6(2);
    q6.enqueue(1);
    q6.enqueue(2);

    cout << "cool Q6:";
    q6.printQueue();

    ArrayQueue<int> q7(5);
    q7.enqueue(9);

    cout << "Q7:";
    q7.printQueue();

    q7 = q6;

    cout << "Q7 as Q6: ";
    q7.printQueue();

    ArrayQueue<string> qstring(2);

    qstring.enqueue("hello");
    qstring.enqueue("world");
    qstring.enqueue("!!!"); // resize

    qstring.printQueue();
    
    return 0;
}