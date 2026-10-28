#include <stdlib.h>

typedef struct linked_list;
struct linked_list
{
    void *data;
    linked_list *next, *previous;
};

struct linked_list_header
{
    int size, data_size;
    linked_list *head, *tail;
};
typedef linked_list_header;

linked_list_header *init_linked_list(int data_size)
{
    linked_list_header *h = (linked_list_header *) malloc(sizeof(linked_list_header));
    if(h == NULL) return NULL;
    h->data_size = data_size;
    h->head = NULL;
    h->tail = NULL;
    return h;
}