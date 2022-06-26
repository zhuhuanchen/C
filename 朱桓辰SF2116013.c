
#include <stdio.h>
#include <stdlib.h>

/*
思路
一般来说外排序分为两个步骤：预处理和合并排序。首先，根据可用内存的大小，将外存上含有n个纪录的文件分成若干长度为t的子文件（或段）；其次，利用内部排序的方法，
对每个子文件的t个纪录进行内部排序。这些经过排序的子文件（段）通常称为顺串(run)，顺串生成后即将其写入外存。这样在外存上就得到了m个顺串（m=[n/t]）。
最后，对这些顺串进行归并，使顺串的长度逐渐增大，直到所有的待排序的记录成为一个顺串为止。

步骤:
1.先将数组拆分为十分，每份1万个数字
2.再对分别将十个数组排序，并写回原数组中
3.最后使用归并排序 使整体有序。
*/

int visit_array(int R[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("R[%d]的值为：%d\n", i, R[i]);
    }
    return 0;
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) //前半段转存到L数组
        L[i] = a[low + i];
    for (j = 0; j < n2; j++) //后半段转存到L数组
        R[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) //归并关键代码
    {
        if (R[j] >= L[i])
            a[k] = L[i++];
        else
            a[k] = R[j++];
        k++;
    }
    while (i < n1) //将任何一个有剩余数字的数组全部依次并入
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main(int argc, char *argv[])
{
    int a[100000];
    for (int i = 0; i < 100000; i++)
    {
        a[i] = rand();
    }

    int b[10000];
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0, k = j * 10000; i < 10, k < (j + 1) * 10000; i++, k++)
        {
            b[i] = a[k];
        }
        mergeSort(b, 0, 9);
        for (int i = 0, k = j * 10000; i < 10, k < (j + 1) * 10000; i++, k++)
        {
            a[k] = b[i];
        }
    }

    int low = 0, high = 99999;
    mergeSort(a, low, high);
    visit_array(a, 100);
}
