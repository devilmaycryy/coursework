#ifndef CELL_H
#define CELL_H
#include <QColor>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "person.h"
class Person;
class Cell:public QGraphicsRectItem //класс который отвечает за создание клетки игрового поля
{
public:
    Cell(QGraphicsItem *parent = 0);
    ~Cell();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    void placePiece(Person *piece);
    void resetOriginalColor();
    bool getHasPerson();
    void setHasPerson(bool value,Person *person = 0);
    int widthL;
    int heightL;
    void setOriginalcolor(QColor value);
    void setPersonColor(QString value);
    QString getPersonColor();
    Person *currentPiece;
private:
    QColor originalColor;
    QBrush brush;
    bool hasPerson;
    QString personColor;
};

#endif // CELL_H

