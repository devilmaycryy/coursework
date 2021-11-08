#ifndef HOWPLAY_H
#define HOWPLAY_H
#include <QGraphicsView>
#include <QLabel>
class HowPlay: public QGraphicsView
{
public:
    HowPlay(QWidget *parent = 0);
private:
    QLabel *label;
};

#endif // HOWPLAY_H
