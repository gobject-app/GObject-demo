#include <stdio.h>
#include "lib/pm-dlist.c"
#include "glib/gprintf.h"

int main() {
    printf("Hello, World !!!\n");

    g_printf("Hello, World GObject !!!\n");

    /*GObject 库的类型管理系统的初始化*/
    g_type_init ();

    PMDList *list;

    /*进行三次对象实例化*/
    for(int i=0;i<3;i++){
        list = g_object_new(PM_TYPE_DLIST, NULL);
        g_object_unref(list);
    }

    /*检查实例是否为GObject对象*/
    list = g_object_new(PM_TYPE_DLIST, "head", NULL, "tail", NULL, NULL);
    if(G_IS_OBJECT(list)){
        g_printf("\t GObject实例\n");
    }else{
        g_printf("\t 不是GObject实例\n");
    }


    return 0;
}
