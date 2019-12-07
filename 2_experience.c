#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

int **a;
int **b;
int **c;

int asize_x;
int asize_y;
int bsize_x;
int bsize_y;
void *routine(void *point)
{
    cout << "现在执行的线程ID为：  ----------------------------------" << pthread_self() << endl;
    int x = ((Point *)point)->x;
    int y = ((Point *)point)->y;
    c[x][y] = 0;
    for (int i = 0; i < asize_y; i++)
    {
        int temp;
        temp = a[x][i] * b[i][y];
        c[x][y] += temp;
        cout<< "a[x][i] = " << a[x][i] <<endl;
        cout<<  "b[i][y] = " << b[i][y] <<endl;
        cout<<"temp = "<< temp << endl;
    }
    cout << "计算目标矩阵的元素： c[" << x << "][" << y << "] = " << c[x][y] << endl
         << endl;
    return point;
}

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    cout << "输入第一个矩阵的行列：";
    cin >> asize_x >> asize_y;

    cout << "输入第二个矩阵的行列：";
    cin >> bsize_x >> bsize_y;

    if (asize_y != bsize_x)
    {
        cout << "wrong input!\n";
        return 0;
    }

    a = new int *[asize_x];
    for (i = 0; i < asize_x; i++)
    {
        a[i] = new int[asize_y];
    }
    b = new int *[bsize_x];
    for (i = 0; i < bsize_x; i++)
    {
        b[i] = new int[bsize_y];
    }

    c = new int *[asize_x];
    for (i = 0; i < asize_x; i++)
    {
        c[i] = new int[bsize_y];
    }

    cout << "输入第一个矩阵的元素： 一共" << asize_x << "行" << asize_y << "列  ";

    for (i = 0; i < asize_x; i++)
    {
        for (j = 0; j < asize_y; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "输入第二个矩阵的元素： 一共" << bsize_x << "行" << bsize_y << "列  ";
    for (i = 0; i < bsize_x; i++)
    {
        for (j = 0; j < bsize_y; j++)
        {
            cin >> b[i][j];
        }
    }
    cout << "第一个矩阵：" << endl;
    for (i = 0; i < asize_x; i++)
    {
        for (j = 0; j < asize_y; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "第二个矩阵：" << endl;
    for (i = 0; i < bsize_x; i++)
    {
        for (j = 0; j < bsize_y; j++)
        {
            cout << b[i][j] << "   ";
        }
        cout << endl;
    }
    
    cout << endl;
    pthread_t *thread = new pthread_t[asize_x * bsize_y];
    
    for (i = 0; i < asize_x; i++)
    {
        for (j = 0; j < bsize_y; j++)
        {
            Point *point = new Point();
            point->x = i;
            point->y = j;

            if (pthread_create(&thread[k++], NULL, routine, point))
            {
                cout << "create thread fail!\n";
                return 0;
            }
        }
    }

    for (i = 0; i < asize_x * bsize_y; i++)
    {
        pthread_join(thread[i], NULL);
    }

    for (i = 0; i < asize_x; i++)
    {
        for (j = 0; j < bsize_y; j++)
        {
            cout << c[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;

    

    for (i = 0; i < asize_x; i++)
    {
        delete a[i];
        delete c[i];
    }
    for (i = 0; i < bsize_x; i++)
    {
        delete b[i];
    }
    delete b;
    delete c;
    delete a;

    return 0;
}
