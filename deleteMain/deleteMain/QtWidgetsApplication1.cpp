#include "QtWidgetsApplication1.h"

#include <QCoreApplication>
#include <QProcess>
#include <QDir>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &QtWidgetsApplication1::deletemine);
}

void QtWidgetsApplication1::deletemine()
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
	args << "/c" << "rmdir" << "/q/s" << pth; // Windows��ɾ���ļ�������
	process->startDetached("cmd.exe", args); // ���������н���0
	exit(0);
}
