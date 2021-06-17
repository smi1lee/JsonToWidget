#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_JsonToWidget.h"
#include "CConfWidgetFactory.h"
#include <QGridLayout>
#include <QPointer>

class JsonToWidget : public QMainWindow
{
    Q_OBJECT

public:
    JsonToWidget(QWidget *parent = Q_NULLPTR);
    void initView();

private:
    Ui::JsonToWidgetClass ui;

    QPointer<QGridLayout> m_pGridLayout = nullptr;
    CConfWidgetFactory* m_pWidgetFactory = nullptr;
};
