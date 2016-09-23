#include "replaceaetemplate.h"
#include <QtWidgets/QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	int ret;

	LoginWindow loginWin;
	if (loginWin.exec() == QDialog::Accepted)
	{
		ReplaceAETemplate w;
		w.show();
		ret = a.exec();
	}

	return ret;
}
