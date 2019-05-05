#include "framer/framer.h"
#include "ui_framer.h"

std::string IMAGE_PATH = ros::package::getPath("framer") + "/utils/logo.jpeg";

Framer::Framer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Framer)
{
    ui->setupUi(this);
    logo.load(IMAGE_PATH.c_str());
    int h = ui->logo_label->height(),w = ui->logo_label->width();
    ui->logo_label->setPixmap(logo.scaled(w,h,Qt::KeepAspectRatio));

}

Framer::~Framer()
{
    delete ui;
}
