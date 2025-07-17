#include <unistd.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void skip_array(int *array, int n)
{
    int i;
    i = 0;
    while( i < n -1)
    {
        array[i + 1] = array[i] + 1;
        i++;
    }
}

void check(int *array, int n)
{
    int j;
    int i;

    j = 1;
    i = n - 1;
    while( i > 0)
    {
        if (array[i] < 10 - j)
        {
            array[i - 1]++;
            array[i] = 0;
        }    
        i--;
        j++;
    }

}

void print_array(int *array, int n)
{
    int i;
    i = 0;
    while (i < n)
    {
        ft_putchar((array[i] % 10) + '0');
        i++;
    }
    if (array[0] != 10 -n)
        write(1, ", ", 2);
    array[n - 1]++;
}

void ft_print_combn(int n)
{
    int array[10];
    int j;

    j = 0;
    array[0] = j;
    skip_array(array , n);
    while(array[0] < 10 - n)
    {
        check(array, n);
        print_array(array, n);
    }
    if (n == 1)
        ft_putchar('9');
}

int main(void)
{
    ft_print_combn(2);
    return 0;
}