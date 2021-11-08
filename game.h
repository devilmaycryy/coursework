#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <field.h>
#include "person.h"

class Game : public QGraphicsView //класс отвечаещий за весь игровой процес
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    void addToScene(QGraphicsItem *item);
    void removeToScene(QGraphicsItem *item);
    void drawField();
    void drawDeadHolder();
    QString getTurn() ;
    void setTurn( QString value);
    void changeTurn();
    Cell *collection[5][5];
    QGraphicsTextItem *check;
    Person *pieceToMove;
    void displayMainMenu();
public slots:
    void start();
    void developers();
    void HowToPlay();
    void nickname();
private:
    QGraphicsScene *scene;
    Field *field;
    QList <QGraphicsItem *> listG;
    QString turn;
    QGraphicsTextItem * turnDisplay;
};
#endif // GAME_H

