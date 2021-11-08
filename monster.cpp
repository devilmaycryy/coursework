#include "monster.h"
#include <game.h>
extern Game *game;
Monster::Monster(QString team,QGraphicsItem *parent):Person(team,parent)
{
setImage();
}
void Monster::setImage(){
    if(side == "MONSTER")
      setPixmap(QPixmap(":/img/images/Monster.png"));
    else if(side == "PRINCESS")
      setPixmap(QPixmap(":/img/images/Princess.png"));
}
void Monster::moves(){
int widt = this->getCurrentBox()->widthL;
int ht = this->getCurrentBox()->heightL;
QString team = this->getSide();
if(ht>0 && !(game->collection[ht-1][widt]->getPersonColor() == team)) {//up
    location.append(game->collection[widt-1][ht]);
    game->collection[widt-1][ht]->setColor(Qt::darkRed);

}
if(ht<7 && !(game->collection[ht+1][widt]->getPersonColor() == team)) {//down
    location.append(game->collection[ht+1][widt]);
    game->collection[ht+1][widt]->setColor(Qt::darkRed);

}
if(widt>0 && !(game->collection[ht][widt-1]->getPersonColor() == team)) {// left
    location.append(game->collection[ht][widt-1]);
    game->collection[ht][widt-1]->setColor(Qt::darkRed);

}
if(widt<7 && !(game->collection[ht][widt+1]->getPersonColor() == team)) {//right
    location.append(game->collection[ht][widt+1]);
    game->collection[ht][widt+1]->setColor(Qt::darkRed);

}
}
