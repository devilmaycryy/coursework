#ifndef NICKNAME_H
#define NICKNAME_H
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QGridLayout>
#include <QPushButton>
class NickName: public QGraphicsView
{
public:
    NickName(QWidget *parent = 0);
/*public slots:
    void next();
*/
private:
    QLabel *label;
    QLineEdit *lineedit;
    QPushButton *button;
    QPushButton *button2;
};

#endif // NICKNAME_H
