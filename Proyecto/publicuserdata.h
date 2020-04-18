#ifndef PUBLICUSERDATA_H
#define PUBLICUSERDATA_H
#include<iostream>

using namespace std;

class PublicUserData
{
public:
    string getUsername() const;
    void setUsername(const string &username);

    string getBio() const;
    void setBio(const string &bio);

    int getFollowers() const;
    void increaseFollowers();
    void decreaseFollowers();

    int getFollowing() const;
private:
    PublicUserData();

protected:
    string _username;
    string _bio;
    int _followers;
    PublicUserData *_following[];
    PublicUserData(const string &username, const string &bio);
};

#endif // PUBLICUSERDATA_H
