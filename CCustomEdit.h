#pragma once

#include <QWidget>
#include <QPointer>
#include <QLineEdit>
#include <QLabel>
#include "CBaseConf.h"

class CCustomEdit : public QWidget, public CBaseConf
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit CCustomEdit(QWidget *parent = nullptr);
    ~CCustomEdit();

    virtual void setName(const QString& strName);
    virtual QString getName();
    virtual void setValue(const QVariant& value);
    virtual QVariant getValue();

private:
    void initView();

private:
    QString m_strValue;
    QPointer<QLineEdit> m_pEdit = nullptr;
    QPointer<QLabel> m_pLabel = nullptr;
};
