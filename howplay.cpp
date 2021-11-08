#include "howplay.h"
#include <QVBoxLayout>
#include <QFont>
HowPlay::HowPlay(QWidget *parent):QGraphicsView(parent)
{
 setFixedSize(1080,600);
 QString l="Game theory is a branch of mathematical economics that studies the resolution of conflicts between players and the optimality of their \n strategies.\nThe conflict can relate to different areas of human interest: most often it is economics, sociology, political science,\nless often biology, cybernetics and even military affairs.\nThe rules\nWe have two players: a monster and a princess.\nEach of them will appear in turn, that is, first a monster appears, he makes his move either to the left or to the right,\nor up or down. As soon as the monster has made its move,it disappears and the princess appears.\nThe princess makes her move either left or right, or up or down. The main task of the monster is to\nfind the princess as quickly as possible,and the task of the princess is not to get caught by the monster.\nAlso, the monster will have its own timer for which it finds time for the princess.";
 label = new QLabel(l,this);
 label->setFont(QFont("Purisa", 13));
 QVBoxLayout *vbox = new QVBoxLayout();
 vbox->addWidget(label);
 setLayout(vbox);
}
