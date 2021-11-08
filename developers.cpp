#include "developers.h"
#include <QVBoxLayout>
Developers::Developers(QWidget *parent):QGraphicsView(parent)
{
setFixedSize(450,357);
QString dev = "Developer Yozhykov Anatolii - working with data\nDeveloper Kolokol Yaroslav - working with algorithms\nDeveloper Glamazdin Dmitry - working with the interface\nDeveloper Mikhail Chernigotsev - working with exceptions";
label = new QLabel(dev,this);
label->setFont(QFont("Purisa",13));
QVBoxLayout *vbox = new QVBoxLayout();
vbox->addWidget(label);
setLayout(vbox);
}
