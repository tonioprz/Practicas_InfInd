#include <QCoreApplication>
#include "person.h"
#include "personlist.h"

int main(int argc, char *argv[])
{
    PersonList pl1;
    pl1.readData();
    pl1.display();
    return 0;
}
