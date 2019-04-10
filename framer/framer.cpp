#include "framer.h"
#include "ui_framer.h"

Framer::Framer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Framer)
{
    ui->setupUi(this);
}

Framer::~Framer()
{
    delete ui;
}
