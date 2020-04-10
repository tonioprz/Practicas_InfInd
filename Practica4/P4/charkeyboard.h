#ifndef CHARKEYBOARD_H
#define CHARKEYBOARD_H
#include"keyboard.h"

class CharKeyboard : public Keyboard
{
public:
    CharKeyboard();
    CharKeyboard(const string &name);
    void process();
};

#endif // CHARKEYBOARD_H
