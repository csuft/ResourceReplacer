#include "replaceaetemplate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ReplaceAETemplate w;
	w.show();
	return a.exec();
}
