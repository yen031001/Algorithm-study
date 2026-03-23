#include <iostream>
using namespace std;

int find_max(int max_num, char* candy,int num);


int main()
{
    int num;
    char* candy;
    char temp;

    cin >> num;
    int max=0;

    candy = (char*)malloc(num * num * sizeof(char));

    char c;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin.get(c);
            if (c == '\n' || c == ' ')
            {
                j--;
                continue;
            }
            candy[(i * num) + j] = c;
        }
    }

    max = find_max(max, candy, num);
    if (max == num)
    {
        cout << max << endl;
        free(candy);
        return 0;
    }

    
    for (int i = 0; i < num ; i++) 
    {
        for (int j = 0; j < num-1; j++)
        {   

            if (candy[i * (num)+j] != candy[i * (num)+j + 1])
            {
                temp = candy[i * num + j];
                candy[i * num + j] = candy[i * num + j + 1];
                candy[i * num + j + 1] = temp;
                max = find_max(max, candy, num);


                temp = candy[i * num + j];
                candy[i * num + j] = candy[i * num + j + 1];
                candy[i * num + j + 1] = temp;
            }
        }
    }


    for (int j = 0; j < num ; j++)
    {


        for (int i = 0; i < num-1; i++)
        {

            if (candy[i * (num)+j] != candy[(i + 1) * (num)+j])
            {
                temp = candy[i * num + j];
                candy[i * num + j] = candy[(i + 1) * num + j];
                candy[(i + 1) * num + j] = temp;
                max = find_max(max, candy, num);


                temp = candy[i * num + j];
                candy[i * num + j] = candy[(i + 1) * num + j];
                candy[(i + 1) * num + j] = temp;
            }
        }
    }
    
    cout << max << endl;


    free(candy);
   
}

int find_max(int max_num, char* candy,int  num)
{
    for (int i = 0; i < num; i++)
    {
        int temp = 1;
        for (int j = 0; j < num-1; j++)
        {
            if (candy[i * (num)+j] == candy[i * (num)+j + 1])
            {
                temp++;
            }
            else
            {
                if (temp > max_num)
                    max_num = temp;
                temp = 1;
            }
        }
        if (temp > max_num)
            max_num = temp;
    }

    for (int j = 0; j < num; j++)
    {
        int temp = 1;
        for (int i = 0; i < num - 1; i++)
        {
            if (candy[i * (num)+j] == candy[(i + 1) * (num)+j])
            {
                temp++;
            }
            else
            {
                if (temp > max_num)
                    max_num = temp;
                temp = 1;
            }
                
        }
        if (temp > max_num)
            max_num = temp;
    }

    return max_num;
}