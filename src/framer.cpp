#include "framer/framer.h"

Framer::Framer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Framer) {
  LOGO_PATH = ros::package::getPath("framer") + "/utils/logo.jpeg";
  VIDEO_PATH = "/media/kookies/DATA/Tiburon/SAVe tasks/path.mp4";
  DESTINATION_PATH = "/home/kookies";
  ui->setupUi(this);
  this->frame_generator();
  logo.load(LOGO_PATH.c_str());
  int h = ui->logo_label->height(), w = ui->logo_label->width();
  connect(ui->prev_frame, SIGNAL(pressed()), this, SLOT(show_prev_frame()));
  connect(ui->next_frame, SIGNAL(pressed()), this, SLOT(show_next_frame()));
  connect(ui->save_frame, SIGNAL(pressed()), this, SLOT(save_present_frame()));
  connect(ui->reset_all, SIGNAL(pressed()), this, SLOT(reset_all()));
  connect(ui->reset_video_path, SIGNAL(pressed()), this,
          SLOT(reset_video_path()));
  connect(ui->reset_destination_path, SIGNAL(pressed()), this,
          SLOT(reset_destination_path()));
}

Framer::~Framer() { delete ui; }

void Framer::show_next_frame() {

  frame_prev = frame_current;
  ui->prev_image->setPixmap(QPixmap::fromImage(
      QImage(frame_prev.data, frame_prev.cols, frame_prev.rows, frame_prev.step,
             QImage::Format_RGB888)));
  cap >> frame_current;
  cv::cvtColor(frame_current, frame_current, CV_BGR2RGB);
  ui->next_image->setPixmap(QPixmap::fromImage(
      QImage(frame_current.data, frame_current.cols, frame_current.rows,
             frame_current.step, QImage::Format_RGB888)));
  count_proc++;
  ui->frame_proc->setText("Frame processed: " + QString::number(count_proc));
}

void Framer::show_prev_frame() {
  ui->prev_image->setPixmap(QPixmap::fromImage(
      QImage(frame_prev.data, frame_prev.cols, frame_prev.rows, frame_prev.step,
             QImage::Format_RGB888)));
  count_proc--;
  ui->frame_proc->setText("Frame processed: " + QString::number(count_proc));
}

void Framer::save_present_frame() {
  count_save++;
  str = std::to_string(count_save);
  frame_name = "frame_" + str + ".png";
  imwrite(DESTINATION_PATH + "/" + frame_name, frame_current);
  ui->frame_save->setText("Frame saved: " + QString::number(count_save));
}

void Framer::reset_all() {
  reset_video_path();
  reset_destination_path();
  this->frame_generator();
}

void Framer::reset_video_path() {
  cap.release();
  cap.open(VIDEO_PATH);
  count_proc = 0;
  ui->frame_proc->setText("Frame processed: " + QString::number(count_proc));
}

void Framer::reset_destination_path() {}

void Framer::frame_generator() {
  cap.open(VIDEO_PATH);
  count_proc = 0;
  count_save = 0;
  ui->frame_proc->setText("Frame processed: " + QString::number(count_proc));
  ui->frame_save->setText("Frame saved: " + QString::number(count_save));
}
