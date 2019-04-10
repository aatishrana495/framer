#ifndef FRAMER_H
#define FRAMER_H

#include <QMainWindow>

namespace Ui {
class Framer;
}

class Framer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Framer(QWidget *parent = 0);
    ~Framer();

private:
    Ui::Framer *ui;
};

#endif // FRAMER_H
