#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_widget.h"

class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = Q_NULLPTR);

public slots:

	void deletemine();

private:
    Ui::widgetClass ui;
};
