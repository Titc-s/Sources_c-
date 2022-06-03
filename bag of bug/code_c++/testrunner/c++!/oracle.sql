#include <stdio.h>
int main()
{
    char c_in;
    while (scanf("%c", &c_in))
    {
        switch (c_in)
        {
        case 'w':
            printf("前进");
        case 'd':
            printf("右");
        case 'a':
            printf("左");
        case 's':
            printf("下");
        default:
            break;
        }
    }
    return 0;
}