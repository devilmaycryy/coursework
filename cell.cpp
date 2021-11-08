#include "cell.h"
#include "game.h"

extern Game *game;
Cell::Cell(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
 setRect(0,0,150,150);
 brush.setStyle(Qt::SolidPattern);
 setZValue(-1);
 setHasPerson(false);
 setPersonColor("NONE");
 currentPiece = NULL;
}
Cell::~Cell(){
    delete this;
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
      //  qDebug() << getChessPieceColor();
        //Deselecting counter part of ChessPiece
        if(currentPiece == game->pieceToMove && currentPiece){

            currentPiece->mousePressEvent(event);
            return;
        }

        //if selected
        if(game->pieceToMove){
            //if same team
            if(this->getPersonColor() == game->pieceToMove->getSide())
                return;
            //removing the eaten piece
            QList <Cell *> movLoc = game->pieceToMove->moveLocation();
            //TO make sure the selected box is in move zone
            int check = 0;
            for(size_t i = 0, n = movLoc.size(); i < n;i++) {
                if(movLoc[i] == this) {
                    check++;

                }
            }
            // if not prsent return
            if(check == 0)
                return;
            //change the color back to normal
             game->pieceToMove->decolor();
             //make the first move false applicable for pawn only
             game->pieceToMove->firstMove = false;
             //this is to eat or consume the enemy present inn the movable region
            if(this->getHasPerson()){
                this->currentPiece->setIsPlaced(false);
                this->currentPiece->setCurrentBox(NULL);


            }
            //changing the new stat and resetting the previous left region
            game->pieceToMove->getCurrentBox()->setHasPerson(false);
            game->pieceToMove->getCurrentBox()->currentPiece = NULL;
            game->pieceToMove->getCurrentBox()->resetOriginalColor();
            placePiece(game->pieceToMove);

            game->pieceToMove = NULL;
            //changing turn
            game->changeTurn();

        }
        //Selecting couterpart of the chessPiece
        else if(this->getHasPerson())
        {
            this->currentPiece->mousePressEvent(event);
        }
}

void Cell::setColor(QColor color){
    brush.setColor(color);
    setBrush(color);
}
void Cell::setOriginalcolor(QColor value){
    originalColor = value;
    setColor(originalColor);
}
void Cell::placePiece(Person *piece)
{

    piece->setPos(x()+75- piece->pixmap().width()/2  ,y()+75-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasPerson(true,piece);
    currentPiece = piece;


}
void Cell::resetOriginalColor(){
    setColor(originalColor);
}
bool Cell::getHasPerson(){
    return hasPerson;
}
void Cell::setHasPerson(bool value, Person *person){
    hasPerson = value;
    if(value)
        setPersonColor(person->getSide());
    else
        setPersonColor("NONE");
}
QString Cell::getPersonColor(){
    return personColor;
}
void Cell::setPersonColor(QString value){
    personColor = value;
}
