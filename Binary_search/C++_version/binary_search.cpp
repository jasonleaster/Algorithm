/**********************************************************
Programmer   :  EOF
E-mail       :  jasonleaster@163.com
File         :  binary_search.cpp
Date         :  2015.07.25

***********************************************************/

#include <iostream>

template<class T>
T BinarySearch(const T p_array[], int start, int end, T target)
{
    if (!p_array || start > end)
    {
        std::cout << "Empty Data set or bad scope " 
                     "try to modify your parameter @start "
                     "or end. And make sure that @start smaller "
                     "than @end" 
                   << std::endl;
        return -1;
    }

    int middle = -1;

    if(p_array[start] == target)
    {
        return start;
    }
    else if(p_array[end] == target)
    {
        return end;
    }

    for(;start < end;)
    {
        middle = (start + end)/2;

        if(p_array[middle] == target)
        {
            return middle;
        }
        else if (p_array[middle] < target)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    std::cout << "The element you find don't exist in the data set" 
              << std::endl;

    return -1;
}

int main()
{
    int array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    int ret = -1;

    ret = BinarySearch(array, 0, sizeof(array)/sizeof(array[0]), 7);

    ret = BinarySearch(array, 0, sizeof(array)/sizeof(array[0]), 12);

    std::cout << ret << std::endl;
    return 0;
}
