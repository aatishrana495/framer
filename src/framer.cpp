#include "framer/framer.h"

Framer::Framer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Framer) {
  logo_path = ros::package::getPath("framer") + "/utils/logo.jpeg";
  load_image_path = ros::package::getPath("framer") + "/utils/load_image.jpeg";
  cap.open("/media/kookies/DATA/Tiburon/SAVe tasks/path.mp4");
  ui->setupUi(this);
  logo.load(logo_path.c_str());
  int h = ui->logo_label->height(), w = ui->logo_label->width();
  frame_current = cv::imread(load_image_path, CV_LOAD_IMAGE_COLOR);
  frame_prev = cv::imread(load_image_path, CV_LOAD_IMAGE_COLOR);
  cv::cvtColor(frame_current, frame_current, CV_BGR2RGB);
  cv::cvtColor(frame_prev, frame_prev, CV_BGR2RGB);
  ui->next_image->setPixmap(QPixmap::fromImage(
      QImage(frame_current.data, frame_current.cols, frame_current.rows,
             frame_current.step, QImage::Format_RGB888)));
  ui->prev_image->setPixmap(QPixmap::fromImage(
      QImage(frame_prev.data, frame_prev.cols, frame_prev.rows, frame_prev.step,
             QImage::Format_RGB888)));
  connect(ui->prev_frame, SIGNAL(pressed()), this, SLOT(show_prev_frame()));
  connect(ui->next_frame, SIGNAL(pressed()), this, SLOT(show_next_frame()));
  connect(ui->save_frame, SIGNAL(pressed()), this, SLOT(save_present_frame()));
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
  ui->frame_save->setText("Frame saved: " + QString::number(count_save));
}

void Framer::frame_generator() {}
