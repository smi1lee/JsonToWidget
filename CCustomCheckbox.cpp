#include "CCustomCheckbox.h"
#include "ComDef.h"

CCustomCheckbox::CCustomCheckbox(QWidget *parent)
    : QCheckBox(parent)
{
    this->setObjectName(_CHECK_NAME_);
}

CCustomCheckbox::~CCustomCheckbox()
{
}

void CCustomCheckbox::setName(const QString& strName)
{
    m_strName = strName;
    this->setText(strName);
}

QString CCustomCheckbox::getName()
{
    return m_strName;
}

void CCustomCheckbox::setValue(const QVariant& value)
{
    this->setChecked(value.toBool());
}

QVariant CCustomCheckbox::getValue()
{
    return this->isChecked();
}
