//
// Created by tonye on 2019-06-04.
//

#ifndef KB_ARTICALE_H
#define KB_ARTICALE_H

#include "kb-bibtex.h"

#define KB_TYPE_ARTICLE (kb_article_get_type())

#define KB_ARTICLE(object) G_TYPE_CHECK_INSTANCE_CAST((object),KB_TYPE_ARTICLE,KbArticle)


typedef struct _KbArticle KbArticle;
struct _KbArticle{
    KbBibtex parent;
};

typedef struct _KbArticleClass KbArticleClass;
struct _KbArticleClass{
    KbBibtexClass parent_class;
};

GType kb_article_get_type(void);

#endif //KB_ARTICALE_H
