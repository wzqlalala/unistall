#include "QtWidgetsApplication1.h"
#include <QCoreApplication>
#include <QProcess>
#include <QDir>
#include <QThread>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	QString pth;
	if (argc < 2)
	{
		return 0;
	}
	pth = QDir::toNativeSeparators(argv[1]);
	QThread::msleep(2000);

	// 创建进程对象
	QProcess *process = new QProcess;

	//// 删除文件
	QStringList args;
	args << "/c" << "rmdir" << "/q/s" << pth; // Windows下删除文件的命令
	process->startDetached("cmd.exe", args); // 启动命令行进程
	exit(0);
	//return 0;
}
