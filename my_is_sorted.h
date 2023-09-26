// Mimic the std:: version in simpler form 
#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

template <typename T>
bool my_is_sorted(T arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return false;
        }
    }
    return true;
}

#endif