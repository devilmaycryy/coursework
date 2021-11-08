#ifndef DEVELOPERS_H
#define DEVELOPERS_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QLabel>
class Developers: public QGraphicsView
{
    Q_OBJECT;
public:
    Developers(QWidget *parent = 0);
private:
    QLabel *label;
};

#endif // DEVELOPERS_H
