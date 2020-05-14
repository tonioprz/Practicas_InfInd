#ifndef BARK_H
#define BARK_H
#include "Publication.hpp"
#include <iostream>
class Bark : public Publication
{

protected:
    string _text;

public:

    string getBark();

    string getText();
    void setText(string bark);

    Bark(int id, unsigned long int time, PublicUserData* user, string text);

    char publicationType();

    ~Bark();
};

#endif // BARK_H
