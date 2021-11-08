#include "person.h"
#include "game.h"
extern Game *game;
Person::Person(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void Person::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Deselect
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
       return;
    }
    //if it is already consumed or not the respective color's turn
    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;
    //selecting
    if(!game->pieceToMove){

        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::red);
        game->pieceToMove->moves();
    }
    //Consuming counterPart of the CHessBox
    else if(this->getSide() != game->pieceToMove->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }


}

void Person::setCurrentBox(Cell *box)
{

    currentBox = box;
}

Cell *Person::getCurrentBox()
{
    return currentBox;
}

QString Person::getSide()
{
    return side;
}

void Person::setSide( QString value)
{
    side = value;
}
QList <Cell *> Person::moveLocation(){
     return location;
}


bool Person::getIsPlaced()
{
    return isPlaced;
}

void Person::setIsPlaced(bool value)
{
    isPlaced = value;

}
void Person::decolor()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
         location[i]->resetOriginalColor();
    }
}

