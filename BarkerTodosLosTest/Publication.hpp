#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <iostream>
#include <vector>

#include"PublicUserData.hpp"

using namespace std;

class Publication
{
protected:
    int _id;
    unsigned long _time;
    PublicUserData* _user;

    Publication(int id, unsigned long int time, PublicUserData* user);

public:
    ~Publication();
    virtual string getBark() = 0;
    int getId();
    unsigned long getTime();
    PublicUserData* getUser();

    void setId(int id);
    void setTime(unsigned long int time);
    void setUser(PublicUserData* user);
    
    //Funcion para saber qué tipo de publicación es
    // b = Bark, r = Rebark, p = Reply
    virtual char publicationType();
};

#endif // PUBLICATION_H
