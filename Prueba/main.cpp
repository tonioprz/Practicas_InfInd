#include "PublicUserData.hpp"
#include "PrivateUserData.hpp"
#include "User.hpp"
#include "Manager.hpp"
#include<iostream>

int main()
{
    std::string email1, email2, email3;
    std::string password1, password2, password3;
    std::string name1, name2, name3;
    std::string bio1, bio2, bio3;


    email1 = "email@domain.com";
    password1 = "1234";
    name1 = "coolGuy98";
    bio1 = "I'm just a random guy living my life";

    email2 = "otheremail@domain.com";
    password2 = "user2pass";
    name2 = "user2";
    bio2 = "Second user of Barker";

    email3 = "fakeemail@domain.com";
    password3 = "user3pass";
    name3 = "user3";
    bio3 = "Third user of Barker";


    Manager manager;
    manager.createUser(email1, password1, name1, bio1);
    manager.createUser(email2, password2, name2, bio2);
    manager.createUser(email3, password3, name3, bio3);

    PublicUserData* user = manager.showUser(name1);

    return 0;
}
