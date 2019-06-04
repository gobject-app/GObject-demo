//
// Created by tonye on 2019-06-04.
//

#ifndef KB_BIBTEX_H
#define KB_BIBTEX_H

#include <glib-object.h>

#define KB_TYPE_BIBTEX (kb_bibtex_get_type())

#define KB_BIBTEX(object) G_TYPE_CHECK_INSTANCE_CAST((object),KB_TYPE_BIBTEX,KbBibtex)


typedef struct _KbBibtex KbBibtex;
struct _KbBibtex{
    GObject parent;
};

typedef struct _KbBibtexClass KbBibtexClass;
struct _KbBibtexClass{
    GObjectClass parent_class;
};


GType kb_bibtex_get_type(void);


/*对象的方法*/
void kb_bibtex_printf(KbBibtex *self);

#endif //KB_BIBTEX_H
