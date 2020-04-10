#ifndef LINEKEYBOARD_H
#define LINEKEYBOARD_H
#include"keyboard.h"

class LineKeyboard : public Keyboard
{
public:
    LineKeyboard();
    LineKeyboard(const string &name);
    void process();
};

#endif // LINEKEYBOARD_H
