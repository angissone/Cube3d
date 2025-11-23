#include "parsing.h"


void new_value(char *new_line, t_node **list_map)
{
    t_node *new;
    t_node *tmp;

    new = malloc(sizeof(t_node));
    if (!new)
        return;
    new->line = new_line;
    new->next = NULL;
    if (*list_map == NULL)
    {
        *list_map = new;
        return;
    }
    tmp = *list_map;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}