#pragma once

#include "CBaseConf.h"
#include <QHash>

class CConfWidgetFactory
{
public:
    explicit CConfWidgetFactory();
    ~CConfWidgetFactory();
    Q_DISABLE_COPY(CConfWidgetFactory)

public:
    void registerWidgetType();
    QVariantList loadConfig(const QString& strConfPath);
    QWidget* getConfWidget(const QString& strWidgetName, const ConfHash& variant);
    void saveConfig(const QString& strConfPath);

private:
    QHash<QString, const QMetaObject*> m_objectHash;
    QList<CBaseConf*> m_ConfList;
};

