#ifndef MONSTER_H
#define MONSTER_H
#include "person.h"

class Monster: public Person //класс отвечающий за монстром
{
public:
    Monster(QString team = "",QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif // MONSTER_H
