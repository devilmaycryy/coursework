#include "field.h"
#include "cell.h"
#include "game.h"
#include "monster.h"

extern Game *game;

Field::Field(){
 setUpMonster();
 setUpPrincess();
}

void Field::drawCells(int x, int y){
    int SHIFT = 150;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Cell *cell = new Cell();
            game->collection[i][j] = cell;
            cell->widthL = i;
            cell->heightL = j;
            cell->setPos(x+SHIFT*j,y+SHIFT*i);
            cell->setOriginalcolor(Qt::yellow);
            game->addToScene(cell);
        }
    }
}
void Field::addPerson(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Cell *cell = game->collection[i][j];
            if(i == 0 && j == 4){
                static int h;
                cell->placePiece(princess[h]);
                game->addToScene(princess[h]);
            }
            if(i == 2 && j == 2){
                static int k;
                cell->placePiece(monster[k]);
                game->addToScene(monster[k]);
            }
        }
    }
}

void Field::reset(){
    int k = 0; int h = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Cell *cell = game->collection[i][j];
            cell->setPersonColor("NONE");
            cell->currentPiece = NULL;
            if(i == 0 && j == 4){
                cell->placePiece(princess[h]);
                princess[h]->setIsPlaced(true);
                princess[h]->firstMove = true;

            }if(i == 2 && j == 0){
                cell->placePiece(monster[k]);
                monster[k]->setIsPlaced(true);
                monster[k]->firstMove = true;
            }
        }
    }
}
void Field::setUpMonster(){
    Person *person;
    person = new Monster("MONSTER");
    monster.append(person);
}
void Field::setUpPrincess(){
    Person *person;
    person = new Monster("PRINCESS");
    princess.append(person);
}

