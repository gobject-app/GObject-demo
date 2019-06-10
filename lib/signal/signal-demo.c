//
// Created by tonye on 2019-06-10.
//

#include "signal-demo.h"

G_DEFINE_TYPE(SignalDemo, signal_demo, G_TYPE_OBJECT);

static void
signal_demo_default_handler(gpointer instance, const gchar *buffer, gpointer userdata){
    g_print("Default handler said: %s\n", buffer);
}


void
signal_demo_init(SignalDemo *self){

}

void
signal_demo_class_init(SignalDemoClass *klass){
    klass->default_handler = signal_demo_default_handler;

    g_signal_new("hello",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST, //信号默认闭包的调用阶段的标识 ,
                 // G_SIGNAL_RUN_FIRST 表示信号的默认闭包要先于信号使用者的闭包被调用

                 G_STRUCT_OFFSET(SignalDemoClass, default_handler), //实现闭包
                 NULL,
                 NULL,
                 g_cclosure_marshal_VOID__STRING,
                 G_TYPE_NONE,
                 1,
                 G_TYPE_STRING
                 );
}