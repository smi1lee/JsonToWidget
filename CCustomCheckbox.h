#pragma once

#include <QCheckBox>
#include "CBaseConf.h"

class CCustomCheckbox : public QCheckBox, public CBaseConf
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit CCustomCheckbox(QWidget *parent = nullptr);
    ~CCustomCheckbox();

    virtual void setName(const QString& strName);
    virtual QString getName();
    virtual void setValue(const QVariant& value);
    virtual QVariant getValue();
};
