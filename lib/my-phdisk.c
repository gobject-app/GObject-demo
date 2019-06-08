//
// Created by tonye on 2019-06-08.
//

#include "my-phdisk.h"

//表明MyPhDisk实现了MyIUsb所规定所有的接口
static void my_phdisk_interface_init(MyIUsbInterface *iface);

//注册实现类，将接口函数的指针指向实际是实现的函数
G_DEFINE_TYPE_WITH_CODE(MyPhdisk, my_phdisk, G_TYPE_OBJECT,
        G_IMPLEMENT_INTERFACE(MY_TYPE_IUSB, my_phdisk_interface_init));


gchar *
my_phdisk_read(MyIUsb *self){
    MyPhdisk *phdisk = MY_PHDISK(self);
    return phdisk->data->str;
}


void my_phdisk_write(MyIUsb *self, const gchar * str) {
    MyPhdisk *phdisk = MY_PHDISK(self);
    g_string_assign(phdisk->data, str);
}

//初始化实例结构体
static void
my_phdisk_init(MyPhdisk *self){
    self->data = g_string_new(NULL);
}

//初始化类结构体
static void
my_phdisk_class_init(MyPhdiskClass *self){

}


//初始化接口结构体
static void
my_phdisk_interface_init(MyIUsbInterface *iface){
    iface->read = my_phdisk_read;
    iface->write = my_phdisk_write;
}