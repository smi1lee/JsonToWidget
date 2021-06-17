#include "CCustomHLine.h"
#include "ComDef.h"

CCustomHLine::CCustomHLine(QWidget *parent)
    : QFrame(parent)
{
    this->setObjectName(_LINE_NAME_);
    this->setFrameShape(QFrame::HLine);
    this->setFrameShadow(QFrame::Sunken);
}

CCustomHLine::~CCustomHLine()
{
}

