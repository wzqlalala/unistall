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

	// �������̶���
	QProcess *process = new QProcess;

	//// ɾ���ļ�
	QStringList args;
	args << "/c" << "rmdir" << "/q/s" << pth; // Windows��ɾ���ļ�������
	process->startDetached("cmd.exe", args); // ���������н���
	exit(0);
	//return 0;
}
