
#include <iostream>
using namespace std;

int min_three(int a, int b, int c)
{
    int min;
    min = a > b ? b : a;
    min = min > c ? c : min;

    return min;
}
int main()
{
    int num;
    cin >> num;

    int* count_table;
    count_table = (int*)malloc((num + 1) * sizeof(int));

    for (int i = 0; i < num + 1; i++)
    {
        count_table[i] = num;
    }

    
    int a;
    int b;
    for (int i = 0; i < num + 1; i++)
    {
        if (i == 0)
        {
            count_table[i] = -1;
            continue;
        }
        else if (i == 1)
        {
            count_table[i] = 0;
            continue;
        }
        else if (i == 2 || i == 3)
        {
            count_table[i] = 1;
            continue;
        }
           


        if (i % 2 == 0)
        {
            a = i / 2;
        }
        else
            a = num;

        if (i % 3 == 0)
        {
            b = i / 3;
        }
        else
            b = num;

        count_table[i] = min_three(count_table[a] + 1, count_table[b] + 1, count_table[i - 1] + 1);
    }

    cout << count_table[num] << endl;

    free(count_table);

}

