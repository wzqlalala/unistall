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

	// 创建进程对象
	QProcess *process = new QProcess;

	// 删除文件
	QStringList args;
	args << "/c" << "rmdir" << "/q/s" << pth; // Windows下删除文件的命令
	process->startDetached("cmd.exe", args); // 启动命令行进程0
	exit(0);
}
