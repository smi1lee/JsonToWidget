#include "CCustomComBox.h"
#include <QHBoxLayout>
#include "ComDef.h"

CCustomComBox::CCustomComBox(QWidget *parent)
    : QWidget(parent)
{
    initView();
}

CCustomComBox::~CCustomComBox()
{
}

void CCustomComBox::setName(const QString& strName)
{
    m_strName = strName;
    m_pLabel->setText(strName);
}

QString CCustomComBox::getName()
{
    return m_strName;
}

void CCustomComBox::setValue(const QVariant& value)
{
    m_pComBox->setCurrentText(value.toString());
}

QVariant CCustomComBox::getValue()
{
    return m_pComBox->currentText();
}

void CCustomComBox::setValueList(const QStringList& strList)
{
    m_pComBox->addItems(strList);
}

QStringList CCustomComBox::getValueList()
{
    QStringList strList;
    for (int i = 0; i < m_pComBox->count(); ++i)
    {
        strList << m_pComBox->itemText(i);
    }
    return strList;
}

void CCustomComBox::initView()
{
    QPointer<QHBoxLayout> pLayout = new QHBoxLayout(this);
    m_pComBox = new QComboBox(this);
    m_pLabel = new QLabel(this);
    m_pComBox->setObjectName(_COMBOX_NAME_);
    m_pLabel->setObjectName(_LABEL_NAME_);
    m_pComBox->setMinimumWidth(100);    
    pLayout->addWidget(m_pLabel);
    pLayout->addWidget(m_pComBox);
    pLayout->addStretch();
    pLayout->setContentsMargins(0, 0, 0, 0);
}
