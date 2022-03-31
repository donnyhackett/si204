#include <iostream>
using namespace std;

bool before(int, int);
void swap(int*);

int main()
{
    int* nums = new int[10];
    for(int i = 0; i < 10; i++)
        cin >> nums[i];
    swap(nums);
    for(int i = 0; i < 10; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}

bool before(int i, int j)
{
    if((i % 2 == 0) && (j % 2 == 0))
        return i < j;
    else if ((i % 2 != 0) && (j % 2 == 0))
        return true;
    else if((i % 2 == 0) && (j % 2 != 0))
        return false;
    else
        return i < j;
}

void swap(int* A)
{
    for(int i = 10; i > 1; i--)
    {
        int max = 0, k;
        for(k = 1; k < i; k++)
            if(before(A[max],A[k]))
                max = k;
        int temp = A[max];
        A[max] = A[i - 1];
        A[i - 1] = temp;
    }
}