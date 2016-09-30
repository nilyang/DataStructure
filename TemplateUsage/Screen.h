#pragma once
#ifndef __SCREEN_H
#define __SCREEN_H

#include<string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default; 

    Screen(pos ht, pos wd, char c)
        :height(ht), width(wd), contents(ht*wd, c) 
    {
    }

    char get() const // 隐式内联
    {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const; //显式内联
    Screen &move(pos r, pos c); //能在之后被设为内联
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};


#endif // !__SCREEN_H
