//
// Created by tonye on 2019-06-06.
//

#include "my-udisk.h"

//表明 MyUdisk 类实现了 MyIUsb 所规定的接口
static void
my_udisk_interface_init(MyIUsbInterface *iface);

//注册实现类，将接口函数的指针指向实际实现的函数
G_DEFINE_TYPE_WITH_CODE(MyUdisk, my_udisk, G_TYPE_OBJECT,
        G_IMPLEMENT_INTERFACE(MY_TYPE_IUSB, my_udisk_interface_init));


//实现接口方法
static gchar*
my_udisk_read (MyIUsb *iusb){

    MyUdisk *udisk = MY_UDISK(iusb);
    return udisk->data->str;
}

void my_udisk_write(MyIUsb *iusb, const gchar *str){
    MyUdisk *udisk = MY_UDISK (iusb);
    g_string_assign(udisk->data, str);
}

//初始化实例结构体
static void
my_udisk_init(MyUdisk *self){
    self->data = g_string_new(NULL);
}


//初始化类结构体
static void
my_udisk_class_init(MyUdiskClass *self){

}

//初始哈接口结构体
static void
my_udisk_interface_init(MyIUsbInterface *iface){
    iface->read = my_udisk_read;
    iface->write = my_udisk_write;
}