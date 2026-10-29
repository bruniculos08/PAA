#include <stdio.h>
#include "list.h"

int main()
{
    printf("starting tests:\n");
    list *p = init_list(10, sizeof(char));
    char data = 'y';
    insert_list(p, (void *) &data);
    print_list(p);
}