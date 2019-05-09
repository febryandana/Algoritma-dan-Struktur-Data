#include <iostream>
#define MAX 10
using namespace std;

int data[MAX];

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort()
{
    int i, j;
    for (i = 1; i < MAX - 1; i++)
    {
        for (j = MAX - 1; j >= i; j--)
        {
            if (data[j - 1] > data[j])
            {
                tukar(&data[j - 1], &data[j]);
            }
        };
    }
}
void shellSort()
{
    int i, j, jarak;
    jarak = MAX;
    bool status;
    while (jarak > 1)
    {
        jarak = jarak / 2;
        status = false;
        while (!status)
        {
            status = true;
            for (j = 0; j < MAX - jarak; j++)
            {
                i = j + jarak;
                if (data[j] > data[i])
                {
                    tukar(&data[j], &data[i]);
                    status = false;
                }
            }
        }
    }
}
void selectionSort()
{
    int i, j, k;
    for (i = 0; i < MAX; i++)
    {
        k = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (data[j] < data[i])
            {
                k = j;
                tukar(&data[i], &data[k]);
            }
        }
    }
}
void insertionSort()
{
    int i, j, x;
    for (i = 1; i < MAX; i++)
    {
        x = data[i];
        j = i - 1;
        while (x < data[j])
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = x;
    }
}
int main()
{
    int i;
    cout << "\nData sebelum diurutkan : ";
    for (i = 0; i < MAX; i++)
    {
        data[i] = rand() % 20 + 1;
        cout << "\nData ke-" << i << " : " << data[i];
    }
    cout << "\nData setelah diurutkan : ";
    // bubbleSort();
    // shellSort();
    // selectionSort();
    insertionSort();
    for (i = 0; i < MAX; i++)
    {
        cout << "\nData ke-" << i << " : " << data[i];
    }
    return 0;
}