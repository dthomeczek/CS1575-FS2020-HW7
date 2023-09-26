// Mimic the std:: version in simpler form
#ifndef MY_SORT_H
#define MY_SORT_H

template <typename T>
void heapify(T arr[], int s, int ind)
{
    int big = ind;
    int l = 2 * ind + 1;
    int r = 2 * ind + 2;

    if ((l < s) && (arr[l] > arr[big]))
    {
        big = l;
    }
    if ((r < s) && (arr[r] > arr[big]))
    {    
        big = r;
    }
    if (big != ind)
    {
        std::swap(arr[ind], arr[big]);
        heapify(arr, s, big);
    }
}

template <typename T>
void my_sort(T arr[], int s)
{
    for (int i = s / 2 - 1; i >= 0; i--)
    {
        heapify(arr, s, i);
    }

    for(int i = s - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

#endif