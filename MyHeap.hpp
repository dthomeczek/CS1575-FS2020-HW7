void get_identity(std::string &my_id)
{
    my_id = "djtpfr";
}

template <typename T>
MyHeap<T>::MyHeap() 
{
    Heap = new T[0]; 
    m_size = 0; 
    NumElems = 0;
}

template <typename T>
MyHeap<T>::MyHeap(T *arr, int s)
{
    Heap = new T[s];
    for (int i = 0; i < s; i++)
    {
        Heap[i] = arr[i];
    }
    m_size = s;
    NumElems = s;
    buildHeap();
}

template <typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
    Heap = new T[source.m_size];
    for (int i = 0; i < source.m_size; i++)
    {
        Heap[i] = source.Heap[i];
    }
    m_size = source.m_size;
    NumElems = source.NumElems;
}

template <typename T>
MyHeap<T>::~MyHeap() 
{
    m_size = 0; 
    NumElems = 0; 
    delete []Heap; 
    Heap = nullptr;
}

template <typename T>
MyHeap<T> &MyHeap<T>::operator=(const MyHeap<T> &source)
{
    if (this != &source)
    {
        delete[] Heap;
        Heap = new T[source.m_size];

        for (int i = 0; i < source.m_size; i++)
        {
            Heap[i] = source.Heap[i];
        }

        NumElems = source.NumElems;
        m_size = source.m_size;
    }
    return *this;
}

template <typename T>
T &MyHeap<T>::top()
{
    return Heap[0];
}

template <typename T>
void MyHeap<T>::pop()
{
    swap(Heap, 0, --NumElems);

    if (NumElems != 0)
    {
        siftDown(0);
        if (NumElems < m_size * 0.25)
        {
            shrinkToFit();
        }
    }
}

template <typename T>
void MyHeap<T>::push(const T &element)
{
    if (m_size == 0)
    {
        m_size = 1;
        delete[] Heap;
        Heap = new T[m_size];
    }

    if (NumElems + 1 >= m_size)
    {
        reserve (m_size * 2);
    }
    if ((NumElems < m_size * 0.25) && NumElems != 0)
    {
        shrinkToFit();
    }
    Heap[NumElems] = element;
    int current = NumElems++;

    while ((current != 0) && (Heap[current] > Heap[parent(current)]))
    {
        swap(Heap, current, parent(current));
        current = parent(current);
    }
}

template <typename T>
void MyHeap<T>::siftDown(int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int biggest = i;

    if (l < NumElems && Heap[l] > Heap[i])
    {
        biggest = l;
    }
    if (r < NumElems && Heap[r] > Heap[biggest])
    {
        biggest = r;
    }
    if (biggest != i)
    {
        swap(Heap, i, biggest);
        siftDown(biggest);
    }
}

template <typename T>
bool MyHeap<T>::empty()
{
    return (NumElems == 0);
}

template <typename T>
int MyHeap<T>::size()
{
    return NumElems;
}

template <typename T>
int MyHeap<T>::sz() 
{
    return m_size;
}

template <typename T>
int MyHeap<T>::leftChild(int pos)
{
    return ((2 * pos) + 1);
}

template <typename T>
int MyHeap<T>::rightChild(int pos)
{
    return ((2 * pos) + 2);
}

template <typename T>
int MyHeap<T>::parent(int pos)
{
    return ((pos - 1) / 2);
}

template <typename T>
bool MyHeap<T>::isLeaf(int pos) 
{
    return ((pos >= NumElems / 2) && (pos < NumElems));
}

template <typename T>
void MyHeap<T>::buildHeap()
{
    for (int i = parent(NumElems - 1); i >= 0; i--)
    {
        siftDown(i);
    }
}

template <typename T>
void MyHeap<T>::swap(T *arr, int firstInd, int secondInd)
{
    T temp = arr[firstInd];
    arr[firstInd] = arr[secondInd];
    arr[secondInd] = temp;
}

template <typename T>
void MyHeap<T>::reserve(int newSize)
{
    if (newSize > m_size)
    {
        m_size = newSize;
        T *temp = new T[m_size];
        for (int i = 0; i < NumElems; i++)
        {
            temp[i] = Heap[i];
        }
        delete[] Heap;
        Heap = temp;
    }
}

template <typename T>
void MyHeap<T>::shrinkToFit()
{
    m_size = NumElems * 2;
    T *temp = new T[m_size];

    for (int i = 0; i < NumElems; i++)
    {
        temp[i] = Heap[i];
    }
    delete[] Heap;
    Heap = temp;
}