#include <iostream>
#include "queue_ds.h"
using namespace std;

int main() {
    queue_ds<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << endl;
    q.print();
    cout << endl;

    cout << "front is " << q.peekFront() << endl;

    q.dequeue();

    cout << endl;
    q.print();

    q.enqueue(60);
    q.enqueue(70);

    cout << endl;
    q.print();

    q.clear();
    cout << endl;
    q.print();

    return 0;
}
