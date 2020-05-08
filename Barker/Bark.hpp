#ifndef BARK_H
#define BARK_H
#include "Publication.h"
using namespace std;

class Bark : public Publication
{
public:
    Bark();
    string getBark();
    string getText();
    void setText(string bark);
    Bark(int id, unsigned long int time, vector<PublicUserData> user, string text);

protected:
    string _text;

};

#endif // BARK_H
