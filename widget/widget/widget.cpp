#include "widget.h"

#include <QCoreApplication>
#include <QProcess>
#include <QDir>

widget::widget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	//QLayout *layout = new QLayout
	//ui.centralWidget->
	connect(ui.pushButton, &QPushButton::clicked, this, &widget::deletemine);
}

void widget::deletemine()
{
	this->close();
	QString filePath = qApp->applicationDirPath();
	QString pth = QDir::toNativeSeparators(filePath);
	//filePath = dir.absolutePath();
	//QString fPath = "E:\\test\\QtWidgetsApplication1\\x64\\Release";

	// �������̶���
	QProcess *process = new QProcess;

	// ɾ���ļ�
	QStringList args;
	args << pth; 
	process->startDetached(pth + "\\deleteMain.exe", args); // ���������н���0
	exit(0);
}
