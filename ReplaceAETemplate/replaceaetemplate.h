#ifndef REPLACEAETEMPLATE_H
#define REPLACEAETEMPLATE_H

#include <QtWidgets/QMainWindow>
#include <QIcon>
#include "ui_replaceaetemplate.h"

class ReplaceAETemplate : public QMainWindow
{
	Q_OBJECT

public:
	ReplaceAETemplate(QWidget *parent = 0);
	~ReplaceAETemplate();

private:
	Ui::ReplaceAETemplateClass ui;
};

#endif // REPLACEAETEMPLATE_H
