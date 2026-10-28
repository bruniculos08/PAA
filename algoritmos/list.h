#include <stdlib.h>
#include <string.h>

#define alloc_memory(pointer, type, size) pointer = (type *) malloc(size); if(pointer == NULL) return NULL;

struct List
{
    void *data;
    int size, data_size, limit;
};
typedef struct List list;


list *init_list(int limit, int data_size)
{
    list *p;
    alloc_memory(p, list, sizeof(list));
    p->size = 0;
    p->data_size = data_size;
    p->limit = limit;
    p->data = malloc(data_size * limit);
    return p;
}

int erase_list(list *p)
{
    free(p->data);
    free(p);
    return 0;
}

int insert_list(list *p, void *data)
{
    if(p->size == p->limit)
        return 1;
    char *node_address = ((char *) p->data) + (p->data_size * p->size);
    if(memcpy((void *) node_address, data, p->data_size) == NULL)
        return 1;
    p->size++;
    return 0;
}

int remove_from_list(list *p, int index)
{
    for(size_t i = p->size - 1; i > index; i--)
    {
        char *front_node_address = ((char *) p->data) + (p->data_size * i);
        char *back_node_address = ((char *) p->data) + (p->data_size * (i - 1));
        memcpy(back_node_address, front_node_address, p->data_size);
    }
    return 0;
}

int print_list(list *p)
{
    char *node_address;
    for (size_t i = 0; i < p->size; i++)
    {
        for (size_t j = 0; j < p->data_size; j++)
        {
            node_address = ((char *) p->data) + i * p->data_size + j;
            printf("%x", *node_address);
        }
        printf(", ");
    }
    printf("\n");
    
}