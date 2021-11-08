#ifndef PERSON_H
#define PERSON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "cell.h"
class Cell;
class Person:public QGraphicsPixmapItem
{
public:
    Person(QString team = "",QGraphicsItem *parent = 0);
    void setCurrentBox(Cell *cell);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Cell *getCurrentBox() ;

    QString getSide() ;
    void setSide( QString value);
     QList <Cell *> moveLocation();
    virtual void setImage() = 0;
    virtual void moves() = 0;
     bool getIsPlaced() ;
     void setIsPlaced(bool value);
     void decolor();
     bool firstMove;

     //bool boxSetting(Cell *cell);
protected:
     Cell *currentBox;
     QString side;
     bool isPlaced;
     QList <Cell *> location;

};

#endif // PERSON_H
