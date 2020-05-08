#ifndef PUBLICUSERDATA_H
#define PUBLICUSERDATA_H
#include<iostream>
#include<vector>


using namespace std;

class Publication;

class PublicUserData
{
private:
    PublicUserData();

protected:


    string _username;
    string _bio;
    int _followers;

    vector<PublicUserData*> _following;

    PublicUserData(const string &username, const string &bio);

    vector<Publication*> _publications;

    ~PublicUserData();

public:

    string getUsername() const;
    void setUsername(const string &username);

    string getBio() const;
    void setBio(const string &bio);

    int getFollowers() const;
    void increaseFollowers() ;
    void decreaseFollowers() ;

    vector<PublicUserData*> getFollowing();

    bool follow(PublicUserData* user);
    bool unfollow(PublicUserData* user);

    vector<Publication*> getPublications();
};

#endif // PUBLICUSERDATA_H
