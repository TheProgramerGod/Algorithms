#include <stdio.h>

void display(int *a, int n)
{
    printf("\nThe elements of the array are : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void insertion(int *b, int n, int p, int e)
{
    for (int i = n - 1; i > p; i--)
    {
        b[i] = b[i - 1];
        b[p] = e;
    }
    printf("\nThe new Array after insertion is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}

void deletion(int *c, int n, int p)
{
    for (int i = p; i < n; i++)
    {
        c[i] = c[i + 1];
        n = n - 1;
    }
    printf("\nThe new Array after deletion is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }
}

int main()
{
    int n;
    int choice;
    int pos;
    int elm;
    printf("\nEnter the number of elements you want to enter in the array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter elements in the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter which operation you want to perform :\n1:displaying the array\n2:inserting an element\n3:Deleting an element \nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        display(arr, n);
        break;
    case 2:
        printf("\nEnter the position you want to insert an element : ");
        scanf("%d", &pos);
        printf("Enter the element you want to enter : ");
        scanf("%d", &elm);
        insertion(arr, n, pos, elm);
        break;
    case 3:
        printf("\nEnter the position you want to delete an element : ");
        scanf("%d", &pos);
        deletion(arr, n, pos);
        break;
    default:
        printf("\nInvalid Input!");
        break;
    }
    return 0;
}