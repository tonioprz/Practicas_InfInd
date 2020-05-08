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

    Publication(int id, unsigned long time, PublicUserData* user);

public:
    ~Publication();
    virtual string getBark() = 0;
    int getId();
    unsigned long getTime();
    PublicUserData* getUser();

    void setId(int id);
    void setTime(unsigned long time);
    void setUser(PublicUserData* user);

};

#endif // PUBLICATION_H
