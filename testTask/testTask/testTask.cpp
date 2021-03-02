#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


void аscendingQuickSort(int* array, int left, int right)
{
    int mainElement;
    int leftSide = left; 
    int rightSide = right;
    mainElement = array[left];
    while (left < right) 
    {
        while ((array[right] >= mainElement) && (left < right))
            right--; 
        if (left != right) 
        {
            array[left] = array[right];
            left++; 
        }
        while ((array[left] <= mainElement) && (left < right))
            left++; 
        if (left != right) 
        {
            array[right] = array[left]; 
            right--; 
        }
    }
    array[left] = mainElement; 
    mainElement = left;
    left = leftSide;
    right = rightSide;
    if (left < mainElement) 
        аscendingQuickSort(array, left, mainElement - 1);
    if (right > mainElement)
        аscendingQuickSort(array, mainElement + 1, right);
}


void descendingQuickSort(int* array, int left, int right)
{
    int mainElement;
    int leftSide = left;
    int rightSide = right;
    mainElement = array[left];
    while (left < right)
    {
        while ((array[right] <= mainElement) && (left < right))
            right--;
        if (left != right)
        {
            array[left] = array[right];
            left++;
        }
        while ((array[left] >= mainElement) && (left < right))
            left++;
        if (left != right)
        {
            array[right] = array[left];
            right--;
        }
    }
    array[left] = mainElement;
    mainElement = left;
    left = leftSide;
    right = rightSide;
    if (left < mainElement)
        descendingQuickSort(array, left, mainElement - 1);
    if (right > mainElement)
        descendingQuickSort(array, mainElement + 1, right);
}

int** func(int n) {
    int* random = new int[16000];
    int** ptrArray = new int*[n];
    for (int count = 1; count <= 15999; count++)
    {  
        random[count-1] = count;
    }
    std::random_shuffle(random,random+15999);
    for (int count = 0; count < n; count++)
    {
        int* mass=new int[random[count]];
        ptrArray[count]=mass;
        for (int i = 0; i < random[count]; i++)
        {
            mass[i] = rand()%32000;
        }
    }

    for (int counter = 0; counter < n; counter++)
    {
        if (counter%2 == 0) {
            аscendingQuickSort(ptrArray[counter], 0, random[counter] - 1);
        }
        else
        {
            descendingQuickSort(ptrArray[counter], 0, random[counter] - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < random[i]; j++)
        {
            cout << ptrArray[i][j] << "; ";
        }
        cout << endl;
    }
    return ptrArray;
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "enter: !\n";
    cin >> n;
    func(n);
    system("pause");
}

