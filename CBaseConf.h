#pragma once

#include <QVariant>
#include <QString>
#include <tuple>

typedef QHash<QString, QVariant> ConfHash;

class CBaseConf
{
public:
    virtual void setSite(int iRow, int iCol, int iRowSpan, int iColSpan) { m_iRow = iRow; m_iCol = iCol; m_iRowSpan = iRowSpan; m_iColSpan = iColSpan; }
    virtual std::tuple<int, int, int, int> getSite() { return std::make_tuple(m_iRow, m_iCol, m_iRowSpan, m_iColSpan); }
    virtual void setWidgetType(const QString& strWidgetName) { m_strWidgetName = strWidgetName; }
    virtual QString getWidgetType() { return m_strWidgetName; }
    virtual void setValueList(const QStringList& strList) { Q_UNUSED(strList) }
    virtual QStringList getValueList() { return QStringList(); }
    virtual void setName(const QString& strName) { m_strName = strName; }
    virtual QString getName() { return m_strName; }
    virtual void setValue(const QVariant& value) { Q_UNUSED(value) }
    virtual QVariant getValue() { return QVariant(); }
    void initData(const ConfHash& valueHash) {
        //QHash<QString, QVariant> valueHash = variant.toHash();
        setWidgetType(valueHash.value("widgetName").toString());
        setName(valueHash.value("name").toString());
        setValueList(valueHash.value("valueList").toStringList());
        setSite(valueHash.value("row").toInt(), valueHash.value("col").toInt(), valueHash.value("rowSpan").toInt(), valueHash.value("colSpan").toInt());
        setValue(valueHash.value("value"));
    }
    QVariant getData() {
        ConfHash valueHash;
        valueHash.insert("widgetName", getWidgetType());
        valueHash.insert("name", getName());
        valueHash.insert("valueList", getValueList());
        valueHash.insert("value", getValue());
        auto tpSite = getSite();
        valueHash.insert("row", std::get<0>(tpSite));
        valueHash.insert("col", std::get<1>(tpSite));
        valueHash.insert("rowSpan", std::get<2>(tpSite));
        valueHash.insert("colSpan", std::get<3>(tpSite));
        return valueHash;
    }

protected:
    QString m_strName = "";
    QString m_strWidgetName = "";
    int m_iRow = 0;
    int m_iCol = 0;
    int m_iRowSpan = 0;
    int m_iColSpan = 0;
};

