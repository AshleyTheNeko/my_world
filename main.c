#include <stdio.h>

int main(void)
{
    char bite[8] = {64, 0, 0, 0, 32, 0, 0, 0};
    printf("%d\n", ((int *)bite)[0]);
    printf("%d\n", ((int *)bite)[1]);
    return 0;
}
