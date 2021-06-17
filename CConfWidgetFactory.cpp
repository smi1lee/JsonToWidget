#include "CConfWidgetFactory.h"
#include "CCustomEdit.h"
#include "CCustomComBox.h"
#include "CCustomCheckbox.h"
#include "CCustomHLine.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

CConfWidgetFactory::CConfWidgetFactory()
{
    m_objectHash.clear();
    m_ConfList.clear();
    registerWidgetType();
}

CConfWidgetFactory::~CConfWidgetFactory()
{
}

void CConfWidgetFactory::registerWidgetType()
{
    //qRegisterMetaType<CCustomEdit>("CCustomEdit");
    const QMetaObject* editObject = &CCustomEdit::staticMetaObject;
    m_objectHash.insert(editObject->className(), editObject);
    const QMetaObject* comboxObject = &CCustomComBox::staticMetaObject;
    m_objectHash.insert(comboxObject->className(), comboxObject);
    const QMetaObject* checkboxObject = &CCustomCheckbox::staticMetaObject;
    m_objectHash.insert(checkboxObject->className(), checkboxObject);
    const QMetaObject* hLineObject = &CCustomHLine::staticMetaObject;
    m_objectHash.insert(hLineObject->className(), hLineObject);
}

QVariantList CConfWidgetFactory::loadConfig(const QString& strConfPath)
{
    QFile* file = new QFile(strConfPath);
    if (!file->open(QIODevice::ReadOnly))
    {
        return QVariantList();
    }
    QByteArray byteArray = file->readAll();
    file->close();
    QJsonParseError* error = new QJsonParseError;
    QJsonDocument doc = QJsonDocument::fromJson(byteArray, error);
    if (error->error == QJsonParseError::NoError)
    {
        //QJsonObject rootObj = doc.object();
        /*rootObj["widget"].toArray()*/
        QJsonArray objArray = doc.array();
        QVariantList valueList;
        for (auto value : objArray)
        {
            QVariant variant = value.toVariant();
            QMap<QString, QVariant> map = variant.toMap();
            valueList << map;
        }
        return valueList;
    }
    return QVariantList();
}

QWidget* CConfWidgetFactory::getConfWidget(const QString& strWidgetName, const ConfHash& variant)
{
    if (m_objectHash.keys().contains(strWidgetName))
    {
        QObject* customObject = m_objectHash.value(strWidgetName)->newInstance();
        if (customObject)
        {
            QWidget* widget = qobject_cast<QWidget*>(customObject);
            CBaseConf* baseConf = dynamic_cast<CBaseConf*>(customObject);
            m_ConfList.append(baseConf);
            baseConf->initData(variant);
            return widget;
        }
    }
    return nullptr;
}

void CConfWidgetFactory::saveConfig(const QString& strConfPath)
{
    QFile* file = new QFile(strConfPath);
    if (!file->open(QIODevice::WriteOnly))
    {
        return;
    }

    QVariantList variantList;
    for (const auto& baseConf : m_ConfList)
    {
        variantList.append(baseConf->getData());
    }
    QJsonArray jsonArray = QJsonArray::fromVariantList(variantList);
    QJsonDocument jsonDoc;
    jsonDoc.setArray(jsonArray);
    file->write(jsonDoc.toJson());
    file->close();
}
