#ifndef REBARK_H
#define REBARK_H
#include "Publication.hpp"

class Rebark : public Publication
{
public:
    Rebark();

    string getBark();

    string getText();
    void setText(string bark);

    Publication* getPublication();
    void setPublication(Publication* publi);
    Rebark(int id, unsigned long int time, Publication* publication, PublicUserData* user, string rebark);

    ~Rebark();

protected:

    string _text;
    Publication* _publication;

};

#endif // REBARK_H
