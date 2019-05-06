#include "framer/framer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Framer w;
	w.show();

	return a.exec();
}
