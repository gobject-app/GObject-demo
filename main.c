#include <stdio.h>
#include "lib/pm-dlist.c"
#include "glib/gprintf.h"
#include "lib/kb-bibtex.c"
#include "lib/kb-articale.c"

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



    g_printf("GObject 对象定义 赋值------------------------------------------\n");

    KbBibtex *entry = g_object_new(KB_TYPE_BIBTEX,
             "title", "The {\\Tex}Book",
             "author", "Knuth, D.E.",
             "publisher", "Addison-Wesley Professional",
             "year",1984,
             NULL
            );


    kb_bibtex_printf(entry);

    g_object_unref(entry);



    g_printf("GObject的子类继承------------------------------------------\n");

    /*GObject 库的类型管理系统的初始化*/
    g_type_init ();
    KbArticle *kbArticle = g_object_new(KB_TYPE_ARTICLE,
                                   "title", "The {\\Tex}Book",
                                   "author", "Knuth, D.E.",
                                   "publisher", "Addison-Wesley Professional",
                                   "year",1984,
                                   //"journal", "Software: Practice and Experience",
                                   "volume", "11",
                                   "number","11",
                                   "pages", "1119-1184",
                                   NULL);


    kb_article_printf(kbArticle);

    g_object_unref(kbArticle);

    return 0;
}

