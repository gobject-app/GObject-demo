//
// Created by tonye on 2019-06-09.
//

#ifndef MY_FILE_H
#define MY_FILE_H

#include <glib-object.h>

#define MY_TYPE_FILE (my_file_get_type())
#define MY_FILE(object) (G_TYPE_CHECK_INSTANCE_CAST((object), MY_TYPE_FILE, MyFile))
#define MY_FILE_CLASS(glass) (G_TYPE_CHECK_CLASS_CAST((glass), MY_TYPE_FILE, MyFileCLass))

typedef struct _MyFile MyFile;
struct _MyFile{
    GObject parent;
};

typedef struct _MyFileClass MyFileClass;
struct _MyFileClass{
    GObjectClass parent_class;
};


GType my_file_get_type(void);



#endif //MY_FILE_H
