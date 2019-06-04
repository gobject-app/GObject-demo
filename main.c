#include <stdio.h>
#include "lib/pm-dlist.c"
#include "glib/gprintf.h"

int main() {
    printf("Hello, World !!!\n");

    g_printf("Hello, World GObject !!!\n");

    g_type_init ();

    PMDList *list;

    for(int i=0;i<3;i++){
        list = g_object_new(PM_TYPE_DLIST, NULL);
        g_object_unref(list);
    }


    return 0;
}

