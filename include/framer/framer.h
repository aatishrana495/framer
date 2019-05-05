#ifndef FRAMER_H
#define FRAMER_H

#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <ros/package.h>				

namespace Ui {
class Framer;
}

class Framer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Framer(QWidget *parent = 0);
    ~Framer();
     QPixmap logo;
private:
    Ui::Framer *ui;
};

#endif // FRAMER_H
