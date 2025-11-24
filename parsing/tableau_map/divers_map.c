#include "parsing.h"

void print_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    printf("\n");
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}
void free_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return;

    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}
