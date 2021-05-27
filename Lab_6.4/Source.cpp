//main.cpp
#include <iostream>
#include <cstring>
#include <cmath>
#include <time.h>

using namespace std;

template <class T> // T - тип
class Massive
{
    T* v; // внутрішній масив
    int size; // кількість елементів
public:
    Massive(int newsize); // конструктор ініціалізації
    Massive(Massive&); // конструктор копіювання
    ~Massive(); // деструктор

    T& operator [] (int index); // індексування
    Massive& operator = (const Massive&); // присвоєння
    friend ostream& operator << <>(ostream&, Massive&); // виведення
    friend istream& operator >> <>(istream&, Massive&); // введення

    Massive& sort(const char*); // сортування
};



template <class T>
Massive<T>::Massive(int newsize) // конструктор ініціалізації
{
    v = new T[size = newsize]; // новий розмір, виділення пам'яті для елементів
    for (int i = 0; i < size; i++) // присвоєння нульових значень елементам
        v[i] = T();
}


template <class T>
Massive<T>::Massive(Massive<T>& x) // конструктор копіювання
{
    v = new T[size = x.size]; // новий розмір, виділення пам'яті для елементів
    for (int i = 0; i < size; i++) // присвоєння значень елементам
        v[i] = x.v[i];
}


template <class T>
Massive<T>::~Massive()
{
    delete[] v; // звільнення пам'яті
}


template <class T>
T& Massive<T>::operator [] (int index)
{
    if (index < 0 || index >= size)
    {
        throw exception("Index out of the range");
    }
    return v[index];
}

template <class T>
Massive<T>& Massive<T>::operator = (const Massive<T>& x)
{
    if (this != &x)
    {
        delete[] v;
        v = new T[size = x.size];
        for (int i = 0; i < size; i++)
            v[i] = x.v[i];
    }
    return *this;
}

template <class T>
istream& operator >> (istream& is, Massive<T>& x)
{
    cout << "Input " << x.size << " elements of massive" << endl;
    for (int i = 0; i < x.size; i++)
    {
        cout << "element[" << i + 1 << "] =  ";
        is >> x.v[i];
    }
    return is;
}

template <class T>
ostream& operator << (ostream& os, Massive<T>& x)
{
    for (int i = 0; i < x.size; i++)
        os << x.v[i] << ' ';
    os << endl;
    return os;
}


template <class T>
Massive<T>& Massive<T>::sort(const char* Down)
{ // Down - порядок сортування
    T x;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)

            if (v[i] < v[j])
            {
                x = v[i];
                v[i] = v[j];
                v[j] = x;
            }
    return *this;
}



int main()
{
    try
    {
        Massive<int> M(5);
        cin >> M;

        M.sort("Down");
        cout << "Sorted down:" << endl;
        cout << M;
    }
    catch (exception e)
    {
        cerr << e.what() << endl;
    }
    system("pause");
    return 0;
}