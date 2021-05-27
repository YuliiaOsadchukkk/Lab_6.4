#include "Massive.h""

template <class T>
Massive<T>::Massive(int newsize) // ����������� �����������
{
    v = new T[size = newsize]; // ����� �����, �������� ���'�� ��� ��������
    for (int i = 0; i < size; i++) // ��������� �������� ������� ���������
        v[i] = T();
}


template <class T>
Massive<T>::Massive(Massive<T>& x) // ����������� ���������
{
    v = new T[size = x.size]; // ����� �����, �������� ���'�� ��� ��������
    for (int i = 0; i < size; i++) // ��������� ������� ���������
        v[i] = x.v[i];
}


template <class T>
Massive<T>::~Massive()
{
    delete[] v; // ��������� ���'��
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
{ // Down - ������� ����������
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
