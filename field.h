#ifndef FIELD_H
#define FIELD_H
#include "person.h"

class Field
{
public:
    Field();
    void drawCells(int x,int y);
    void setUpPrincess();
    void setUpMonster();
   void addPerson();
    void reset();
private:
    QList<Person *> monster;
    QList<Person *> princess;

};

#endif // FIELD_H
