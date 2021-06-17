#pragma once

#include <QFrame>
#include "CBaseConf.h"

class CCustomHLine : public QFrame, public CBaseConf
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit CCustomHLine(QWidget *parent = nullptr);
    ~CCustomHLine();
};
