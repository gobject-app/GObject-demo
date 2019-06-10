//
// Created by tonye on 2019-06-09.
//

#include "my-file.h"

G_DEFINE_TYPE(MyFile, my_file, G_TYPE_OBJECT);

#define MY_FILE_GET_PRIVATE(object) (G_TYPE_INSTANCE_GET_PRIVATE((object),MY_TYPE_FILE, MyFilePrivate))

typedef struct _MyFilePrivate MyFilePrivate;

struct _MyFilePrivate{
    GString *name;
    GIOChannel *file;
};

enum PropertyDList{
    PROPERTY_FILE_0,
    PROPERTY_FILE_NAME,
    N_PROPERTIES
};


static void
my_file_set_property(GObject *object, guint property_id,
        const GValue *value, GParamSpec *pspec){
    MyFile *self = MY_FILE(object);
    MyFilePrivate *priv = MY_FILE_GET_PRIVATE(self);
    switch(property_id){
        case PROPERTY_FILE_NAME:
            if(priv->name){
                g_string_free(priv->name, TRUE);
            }
            priv->name = g_string_new(g_value_get_string(value));
            priv->file = g_io_channel_new_file(priv->name->str, "a+", NULL);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}

static void
my_file_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec){
    MyFile *self = MY_FILE(object);
    MyFilePrivate *priv = MY_FILE_GET_PRIVATE(self);
    switch(property_id){
        case PROPERTY_FILE_NAME:
            g_value_set_string(value, priv->name->str);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}

//dispose阶段 解除对象对其所有属性的引用，可以执行多次
static void
my_file_dispose(GObject *object){
    MyFile *self = MY_FILE(object);
    MyFilePrivate *priv = MY_FILE_GET_PRIVATE(self);
    if(priv->file){
        g_io_channel_unref(priv->file);
        priv->file = NULL;
    }
    G_OBJECT_CLASS(my_file_parent_class)->dispose(object);
}

//finalize阶段 释放对象所有占有的资源，仅执行一次
static void
my_file_finalize(GObject *object){
    MyFile *self = MY_FILE(object);
    MyFilePrivate *priv = MY_FILE_GET_PRIVATE(self);
    g_string_free(priv->name, TRUE);

    G_OBJECT_CLASS(my_file_parent_class)->finalize(object);
}

static
void my_file_init(MyFile *self){

}


static
void my_file_class_init(MyFileClass *klass){
    g_type_class_add_private(klass, sizeof(MyFilePrivate));
    GObjectClass *base_class = G_OBJECT_CLASS(klass);
    base_class->set_property = my_file_set_property;
    base_class->get_property = my_file_get_property;
    base_class->dispose = my_file_dispose;
    base_class->finalize = my_file_finalize;

    GParamSpec *properties[N_PROPERTIES] = {NULL,};
    properties[PROPERTY_FILE_NAME] = g_param_spec_string("name",
            "Name",
            "File Name",
            NULL,
            G_PARAM_READWRITE | G_PARAM_CONSTRUCT
            );
    g_object_class_install_properties(base_class, N_PROPERTIES, properties);

    g_signal_new("file_changed",   //信号名称
                 MY_TYPE_FILE,     //类的类型 ID
                 G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,

                 0,  //内存偏移量，主要用于从 SignalDemoClass 结构体中找到 default_handler 指针的位置，
                 // 可以使用 G_STRUCT_OFFSET 宏来获取，也可以直接根据 signal-demo.h 中的 SignalDemoClass 结构体的定义，
                 // 使用 sizeof (GObjectClass) 来得到内存偏移量，因为 default_handler 指针之前只有一个 GObjectClass 结构体成员

                 NULL,
                 NULL,

                 g_cclosure_marshal_VOID__VOID, //设定闭包的marshal 视为回调函数 + 上下文环境而构成的一种数据结构
                 //marshal 主要是用来“翻译”闭包的参数和返回值类型的，它将翻译的结果传递给闭包
                 //之所以不直接调用闭包，而是在其外加了一层 marshal 的包装，主要是方便 GObject 库与其他语言的绑定

                 G_TYPE_NONE, //指定 marshal 函数的返回值类型 VOID对应G_TYPE_NONE
                 0 //指定 g_signal_new 函数向 marshal 函数传递的参数个数,
                 );
}


void
my_file_write(MyFile *self, gchar *buffer){
    MyFilePrivate *priv = MY_FILE_GET_PRIVATE(self);
    g_io_channel_write_chars(priv->file, buffer, -1, NULL, NULL);
    g_io_channel_flush(priv->file, NULL);

    g_signal_emit_by_name(self, "file_changed");
}

