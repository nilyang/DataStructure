#include "Screen.h"



inline char Screen::get(pos ht, pos wd) const
{
    pos row = ht * width;
    return contents[row + wd];
}

inline Screen & Screen::move(pos r, pos c)
{
    // TODO: 在此处插入 return 语句
}
