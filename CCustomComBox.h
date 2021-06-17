#pragma once

#include <QComboBox>
#include <QPointer>
#include <QLabel>
#include "CBaseConf.h"

class CCustomComBox : public QWidget, public CBaseConf
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit CCustomComBox(QWidget *parent = nullptr);
    ~CCustomComBox();

    virtual void setName(const QString& strName);
    virtual QString getName();
    virtual void setValue(const QVariant& value);
    virtual QVariant getValue();
    virtual void setValueList(const QStringList& strList) override;
    virtual QStringList getValueList() override;

private:
    void initView();

private:
    QPointer<QComboBox> m_pComBox = nullptr;
    QPointer<QLabel> m_pLabel = nullptr;
};
