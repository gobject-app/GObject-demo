#include <stdio.h>
#include "lib/pm-dlist.h"
#include "glib/gprintf.h"
#include "lib/kb-bibtex.h"
#include "lib/kb-articale.h"
#include "lib/my-udisk.h"
#include "lib/my-phdisk.h"

#include "lib/gclosure/gclosure-no.c"
#include "lib/gclosure/gclosure-do.c"

#include <stdlib.h>
#include <string.h>


#include "lib/signal/my-file.h"
#include "lib/signal/signal-demo.h"
#include "lib/accumulator/accumusignal-demo.h"



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


static void
file_print(gpointer gobject, gpointer user_data){
    g_printf("invoking file_print!\n");
}

static void
file_print_xml(gpointer gobject, gpointer user_data){
    g_printf("invoking file_print_xml!\n");
}

static void
file_print_text(gpointer gobject, gpointer user_data){
    g_printf("invoking file_print_text!\n");
}


static gchar
my_signal_handler(gpointer *instance, gchar *buffer, gpointer userdata){
    g_print("my_signal_handler said: %s\n", buffer);
    g_print("my_signal_handler said: %s\n", (gchar *)userdata);
}

static gint
my_accumusignal_handler(gpointer *instance, gchar *buffer, gpointer userdata){
    g_print("my_accumusignal_handler said: %s\n", buffer);
    g_print("my_accumusignal_handler said: %s\n", (gchar *)userdata);
    return 1;
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

    gchar *aa;

    g_object_get(G_OBJECT(kbArticle), "pages", &aa, NULL);
    g_object_set(G_OBJECT(kbArticle), "volume", aa, NULL);
    g_object_set(G_OBJECT(kbArticle), "journal", aa, NULL);


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


    g_printf("C闭包 gclosure-no------------------------------------------\n");
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

    g_printf("GObject闭包  gclosure-do------------------------------------------\n");
    gfloat ga = 123.234234;
    gfloat gb = 222.3434;

    GClosure *closure = g_cclosure_new(G_CALLBACK(float_compare3), &ga, NULL);
    g_closure_set_marshal(closure, g_cclosure_user_marshal_INT__VOID_VOID);
    compare3(closure, &gb);


    gchar *gs1 = "Hello World!\n";
    gchar *gs2 = "Hello! \n";
    closure = g_cclosure_new(G_CALLBACK(str_compare3), gs1, NULL);
    g_closure_set_marshal(closure, g_cclosure_user_marshal_INT__VOID_VOID);
    compare3(closure, gs2);
    g_closure_unref(closure);


    g_printf("GObject 信号的事件响应------------------------------------------\n");

    MyFile *file = g_object_new(MY_TYPE_FILE, "name","test.txt", NULL);

    g_signal_connect(file, "file_changed", G_CALLBACK(file_print), NULL);
    g_signal_connect(file, "file_changed", G_CALLBACK(file_print_xml), NULL);
    g_signal_connect(file, "file_changed", G_CALLBACK(file_print_text), NULL);

    my_file_write(file, "hello world!\n");

    g_object_unref(file);



    g_printf("GObject 信号机制——信号注册------------------------------------------\n");
    gchar *userdata = "This is userdata";
    SignalDemo *signalDemo = g_object_new(SIGNAL_TYPE_DEMO, NULL);

    //信号连接
    g_signal_connect(signalDemo, "hello", G_CALLBACK(my_signal_handler), userdata);

    //发射信号
    g_signal_emit_by_name(signalDemo, "hello", "This the second param", G_TYPE_NONE);

    g_object_unref(signalDemo);


    g_printf("GObject 信号机制——信号返回值 Accumulator------------------------------------------\n");

    AccumusignalDemo *accumusignalDemo = g_object_new(ACCUMUSIGNAL_TYPE_DEMO, NULL);

    gint val = 0; //val 参数可以保存最后一个信号闭包的返回值

    //信号连接
    g_signal_connect(accumusignalDemo, "acc",
            G_CALLBACK(my_accumusignal_handler),
            userdata);

    //发射信号
    g_signal_emit_by_name(accumusignalDemo,
            "acc",
            "This the second param",
            &val);

    g_object_unref(accumusignalDemo);
    return 0;
}

