#include "CCustomEdit.h"
#include <QHBoxLayout>
#include "ComDef.h"

CCustomEdit::CCustomEdit(QWidget *parent)
    : QWidget(parent)
{
    initView();
}

CCustomEdit::~CCustomEdit()
{
}

void CCustomEdit::initView()
{
    QPointer<QHBoxLayout> pLayout = new QHBoxLayout(this);
    m_pLabel = new QLabel;
    m_pLabel->setObjectName(_LABEL_NAME_);
    m_pEdit = new QLineEdit;
    m_pEdit->setObjectName(_EDIT_NAME_);
    m_pEdit->setMaximumWidth(240);
    pLayout->addWidget(m_pLabel);
    pLayout->addWidget(m_pEdit);
    pLayout->addStretch();
    pLayout->setContentsMargins(0, 0, 0, 0);
}

void CCustomEdit::setName(const QString& strName)
{
    m_strName = strName;
    m_pLabel->setText(strName);
}

QString CCustomEdit::getName()
{
    return m_strName;
}

void CCustomEdit::setValue(const QVariant& value)
{
    m_strValue = value.toString();
    m_pEdit->setText(m_strValue);
}

QVariant CCustomEdit::getValue()
{
    return m_pEdit->text();
}
