#ifndef FRAMER_H
#define FRAMER_H

#include "ui_framer.h"
#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <ros/package.h>
#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <string>

namespace Ui {
class Framer;
}

class Framer : public QMainWindow {
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
  void reset_all();
  void reset_video_path();
  void reset_destination_path();

private:
  Ui::Framer *ui;
  cv::VideoCapture cap;
  std::string LOGO_PATH, load_image_path, VIDEO_PATH, DESTINATION_PATH;
  int count_proc, count_save;
  cv::Mat frame_current, frame_prev;
};

#endif // FRAMER_H
