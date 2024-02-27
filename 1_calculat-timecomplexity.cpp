//  T(n) = n2 → O(n^2)
// T(n) = logn → O(logn)

// ==>1
#include<stdio.h>

void func1(int array[], int length)
{
    int sum=0;
    int product =1;
    for (int i = 0; i <length; i++)
    {
        sum+=array[i];
    }
 
    for (int i = 0; i < length; i++)
    {
        product*=array[i];
    }
}
 
int main()
{
    int arr[] = {3,4,66};
    func1(arr,3);
    return 0;
}


// // ==>2
// void func(int n)
// {
//     int sum=0;
//     int product =1;
//     for (int i = 0; i <n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             printf("%d , %d\n", i,j);
//         }
//     }
// }


// // ==>3
// int function(int n)
// {
//     int i = 0;
//     if (n <= 0)
//     {
//         return 0;
//     }
//     else
//     {
//         i = random(n - 1);
//         printf("this\n");
//         return function(i) + function(n - 1 - i);
//     }
// }


// // ==>5
// int sum(Node node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     return sum(node.left) + node.value + sum(node.right);
// }


// // ==>6
// int sum(Node node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     return sum(node.left) + node.value + sum(node.right);
// }


// // ==>7
// int isPrime(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     for (int i = 2; i * i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }


// // ==>8
// int isPrime(int n)
// {
//     for (int i = 2; i * i < 10000; i++)
//     {
//         if (n % i == 0)
//         {
//             return 0;
//         }
//     }
 
//     return 1;
// }
// isPrime();