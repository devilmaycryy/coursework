#include "game.h"
#include "developers.h"
#include "howplay.h"
#include "nickname.h"
#include <button.h>
Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    //размер сцены
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1400,800);
    //размер фиксированого окна
    setFixedSize(1400,800);
    setScene(scene);

    pieceToMove = NULL;
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-300,20);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : MONSTER");
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
     setTurn("MONSTER");
}
QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

void Game::changeTurn()
{
    if(getTurn() == "MONSTER")
        setTurn("PRINCESS");
    else
        setTurn("MONSTER");
    turnDisplay->setPlainText("Turn : " + getTurn());
}
void Game::drawField(){
    field = new Field();
    field->drawCells(width()/2 -300,150);

}
void Game::addToScene(QGraphicsItem *item){
    scene->addItem(item);
}
void Game::removeToScene(QGraphicsItem *item){
    scene->removeItem(item);
}
void Game::start(){
    for(size_t i =0, n = listG.size(); i < n; i++)
        removeToScene(listG[i]);

    addToScene(turnDisplay);
    /*QGraphicsTextItem* whitePiece = new QGraphicsTextItem();
    whitePiece->setPos(70,10);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::white);
    whitePiece->setFont(QFont("",14));
    whitePiece->setPlainText("WHITE PIECE");
    addToScene(whitePiece);
    QGraphicsTextItem *blackPiece = new QGraphicsTextItem();

    blackPiece->setPos(1170,10);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::black);
    blackPiece->setFont(QFont("",14));
    blackPiece->setPlainText("BLACK PIECE");
    addToScene(blackPiece);*/
    addToScene(check);
    field->addPerson();
}
void Game::developers(){
    Developers *dev = new Developers();
    dev->show();
}
void Game::HowToPlay(){
    HowPlay *hp = new HowPlay();
    hp->show();
}
void Game::nickname(){
    NickName *nick = new NickName();
    nick->show();

}
void Game::displayMainMenu()
{
    /*QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
    p->setPixmap(QPixmap(":/img/images/Monster.png"));
    p->setPos(300,170);
    addToScene(p);
    listG.append(p);

    QGraphicsPixmapItem *p1 = new QGraphicsPixmapItem();
    p1->setPixmap(QPixmap(":/img/images/Princess.png"));
    p1->setPos(920,170);
    addToScene(p1);
    listG.append(p1);*/

    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Monster and Princess");
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = 750 - titleText->boundingRect().width()/2;
    int yPos = 60;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);

    //create Button
    Button * playButton = new Button("Play");
    int pxPos = 750 - playButton->boundingRect().width()/2;
    int pyPos = 160;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    addToScene(playButton);
    listG.append(playButton);

    //create NickName Button
    Button *nickname = new Button("NickName");
    int hxpos = 750 - nickname->boundingRect().width()/2;
    int hypos = 460;
    nickname->setPos(hxpos,hypos);
    connect(nickname,SIGNAL(clicked()),this,SLOT(nickname()));
    addToScene(nickname);
    listG.append(nickname);

    //create Developers Button
    Button *developersButton = new Button("Developers");
    int kxpos = 750 - developersButton->boundingRect().width()/2;
    int kypos = 235;
    developersButton->setPos(kxpos,kypos);
    connect(developersButton,SIGNAL(clicked()),this,SLOT(developers()));
    addToScene(developersButton);
    listG.append(developersButton);

    //create How To play Button
    Button *howtoplayButton = new Button("How To Play");
    int rxpos = 750 - howtoplayButton->boundingRect().width()/2;
    int rypos = 310;
    howtoplayButton->setPos(rxpos,rypos);
    connect(howtoplayButton,SIGNAL(clicked()),this,SLOT(HowToPlay()));
    addToScene(howtoplayButton);
    listG.append(howtoplayButton);

    //Create Quit Button
    Button * quitButton = new Button("Quit");
    int qxPos = 750 - quitButton->boundingRect().width()/2;
    int qyPos = 385;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
    drawField();
    //field->addPerson();
    listG.append(quitButton);
}



