#include "JsonToWidget.h"
#include <QPushButton>
#include <QLayout>

JsonToWidget::JsonToWidget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initView();
}

void JsonToWidget::initView()
{
    m_pWidgetFactory = new CConfWidgetFactory;
    m_pGridLayout = new QGridLayout;
    QVariantList valueList = m_pWidgetFactory->loadConfig("./confview.json");
    for (auto& valueData : valueList)
    {
        QHash<QString, QVariant> valueHash = valueData.toHash();
        QWidget* widget = m_pWidgetFactory->getConfWidget(valueHash.value("widgetName").toString(), valueHash);
        if (widget)
        {
            m_pGridLayout->addWidget(widget, valueHash.value("row").toInt(), valueHash.value("col").toInt(), valueHash.value("rowSpan").toInt(), valueHash.value("colSpan").toInt());
        }        
    }

    QPointer<QVBoxLayout> pTopLayout = new QVBoxLayout(ui.centralWidget);
    QPointer<QHBoxLayout> pBtnLayout = new QHBoxLayout;
    QPointer<QPushButton> pSaveBtn = new QPushButton("Save");
    connect(pSaveBtn, &QPushButton::clicked, this, [=]() {
        m_pWidgetFactory->saveConfig("./confview1.json");
        });
    pBtnLayout->addStretch();
    pBtnLayout->addWidget(pSaveBtn);
    pTopLayout->addLayout(m_pGridLayout);
    pTopLayout->addStretch();
    pTopLayout->addLayout(pBtnLayout);
}
