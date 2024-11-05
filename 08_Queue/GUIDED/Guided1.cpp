#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull()
{
    return back == maksimalQueue;
}

bool isEmpty()
{
    return back == 0;
}

void enqueueAntrian(string data)
{
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        queueTeller[back] = data;
        back++;
    }
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            cout << "Antrian ke-" << i + 1 << " : " << queueTeller[i] << endl;
        }
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back - 1; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = "";
        back--;
    }
}

int countQueue()
{
    return back;
}

void clearQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        front = 0;
        back = 0;
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian : " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian : " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian : " << countQueue() << endl;
    return 0;
}
