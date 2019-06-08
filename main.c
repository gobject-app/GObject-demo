#include <stdio.h>
#include "lib/pm-dlist.h"
#include "glib/gprintf.h"
#include "lib/kb-bibtex.h"
#include "lib/kb-articale.h"
#include "lib/my-udisk.h"
#include "lib/my-phdisk.h"

#include "lib/no-gclosure.c"

#include <stdlib.h>
#include <string.h>




int
foo (void){
    return 1;
}

typedef int (*Func)(void);



static int
str_compare(const void *s1, const void *s2){
    //g_printf("==%s\n",*(char **)s1);  //获取列表中指针的指针对应的值

    char *str1 = *(char **)s1;
    char *str2 = *(char **)s2;
    size_t l1 = strlen(str1);
    size_t l2 = strlen(str2);

    if(l1>l2){
        return 1;
    }else if(l1 == l2){
        return 0;
    }else{
        return -1;
    }

}


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


    g_printf("GObject的接口实现------------------------------------------\n");

    MyUdisk *udisk = g_object_new (MY_TYPE_UDISK, NULL);

    my_iusb_write (MY_IUSB (udisk), "I am u-disk!");

    gchar *data = my_iusb_read (MY_IUSB (udisk));

    g_printf("%s\n\n", data);

    g_printf ("Is udisk a MyIUsb object?\n");


    if (MY_IS_IUSB (udisk)){
        g_printf ("Yes!\n");
    }else{
        g_printf ("No!\n");
    }

    g_printf ("\nIs udisk a MyUdisk object?\n");
    if (MY_IS_UDISK (udisk)){
        g_printf ("Yes!\n");
    }else{
        g_printf ("No!\n");
    }




    MyPhdisk *phdisk = g_object_new(MY_TYPE_PHDISK, NULL);
    my_iusb_write(MY_IUSB(phdisk),"I am a phdisk!");
    data = my_iusb_read(MY_IUSB(phdisk));
    g_printf("%s\n",data);



    g_printf("函数指针------------------------------------------\n");


    Func func = foo;
    g_printf("%d\n",func());



    g_printf("回调函数------------------------------------------\n");

    char *str_array[5] = {"a", "abcd", "abc", "ab", "abcde"};

    qsort(str_array, 5, sizeof(char *), str_compare);

    for(int i = 0;i<5;i++){
        g_printf("%s\t\n", str_array[i]);
    }


    g_printf("GObject闭包------------------------------------------\n");
    /**
     * 闭包：就是一个函数加上它所有访问的所有非局部变量，这些变量对于那个函数而言即非全局变量，也非局部变量
     * 因此，str_compare与这2个参数形成一个闭包
     * 函数可以存储在变量中，可以作为实参传递给其他函数，还可以作为其他函数的返回值
     */

    float a = 123123.3434;
    float b = 2222.33423;
    Func2 func2 = float_compare2;
    compare2(&a, &b, func2);

    char *s1 = "hello world!";
    char *s2 = "hello !";
    func2 = str_compare2;
    compare2(s1, s2, func2);







    return 0;
}

