#ifndef QUEUE_DS_H
#define QUEUE_DS_H
#include <iostream>
using namespace std;

template<typename T>
class queue_ds
{
private:

    T*arr;

    int size;
    int capacity;
    int front;
    int back;

    bool isEmpty () const
    {
        return size==0;
    }

    bool isFull () const
    {
        return size==capacity;
    }

    void resize(size_t newCapacity)
    {
        if (size > capacity)
        {
            throw runtime_error("overflow");
            cout<<endl;
        }

        T* newArr = new T[newCapacity];
        size_t temp = front;

        for (size_t i = 0; i < size; i++)
        {
            newArr[i] = arr[temp];
            temp = (temp + 1) % capacity;
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        back = size - 1;
    }

public:
    queue_ds(int cap=5)
    {
        capacity=cap;
        size=0;
        front=0;
        back=-1;
        arr=new T[capacity];
    }

    void enqueue(const T& val)
    {
        if(isFull())
        {
            resize(capacity+10);
        }
        back=(back+1)%capacity;
        arr[back]=val;
        size++;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            throw runtime_error("empty queue");
        }
        cout<<"dequeue element is : "<<arr[front]<<endl;
        front=(front+1)%capacity;
        size--;
    }

    T peekFront() const
    {
        if(isEmpty())
        {
            throw runtime_error("empty queue");
        }
        return arr[front];
    }

    void print() const
    {
        if (isEmpty())
        {
            cout << "empty queue" << endl;
            return;
        }
        int temp=front;
        for(int i=0; i<size; i++)
        {
            cout<<arr[temp]<<" ";
            temp=(temp+1)%capacity;
        }
    }

    void clear()
    {
        size = 0;
        front = 0;
        back = -1;
    }

    ~queue_ds()
    {
        delete[]arr;
    }


};

#endif // QUEUE_DS_H
