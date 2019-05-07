#ifndef FRAMER_H
#define FRAMER_H

#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <ros/package.h>
#include "ui_framer.h"

#include <boost/lexical_cast.hpp>
#include <string>



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
public slots:
	void show_next_frame();
	void show_prev_frame();
	void save_present_frame();
	void frame_generator();

private:
	Ui::Framer *ui;
	int count_proc,count_save;
	
};

#endif // FRAMER_H
