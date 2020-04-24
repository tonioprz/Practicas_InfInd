#ifndef PUBLICUSERDATA_H
#define PUBLICUSERDATA_H
#include<iostream>
#include<vector>

using namespace std;

class PublicUserData
{
private:

protected:
    PublicUserData();

    string _username;
    string _bio;
    int _followers;
    vector<PublicUserData*> _following;
    PublicUserData(const string &username, const string &bio);
    ~PublicUserData();

public:

    string getUsername() const;
    void setUsername(const string &username);

    string getBio() const;
    void setBio(const string &bio);

    int getFollowers() const;
    void increaseFollowers() ;
    void decreaseFollowers() ;

    int getFollowing();


};

#endif // PUBLICUSERDATA_H
