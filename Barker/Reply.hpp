#ifndef REPLY_H
#define REPLY_H
#include "Publication.hpp"

class Reply : public Publication
{
public:
    Reply();

    string getBark();

    string getText();
    void setText(string reply);

    Publication* getPublication();
    void setPublication(Publication* publi);

    Reply(int id, unsigned long int time, Publication* publication, PublicUserData* user, string reply);

    ~Reply();

protected:
    string _text;
    Publication* _publication;
};

#endif // REPLY_H
