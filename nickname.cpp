#include "nickname.h"

NickName::NickName(QWidget *parent):QGraphicsView(parent)
{
resize(447,357);
QString text = "Your NickName: ";
label = new QLabel(text,this);
label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
lineedit = new QLineEdit(this);
button = new QPushButton("Next",this);
button2 = new QPushButton("Cancel",this);
connect(button,SIGNAL(clicked()),this,SLOT(close()));
connect(button2,SIGNAL(clicked()),this,SLOT(close()));
QGridLayout *grid = new QGridLayout();
grid->addWidget(label, 0, 0);
grid->addWidget(lineedit, 0, 1);
grid->addWidget(button,1,0);
grid->addWidget(button2,1,1);
setLayout(grid);

}

