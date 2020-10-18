#include "TableModel.h"

#include <QTextStream>

TableModel::TableModel(QString path, QObject *parent) : QAbstractTableModel(parent), m_filePath(path)
{
}

bool TableModel::load()
{
    QFile file(m_filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;

    QStringList fileStrings;
    QTextStream stream(&file);
    while(!stream.atEnd()) {
        fileStrings << stream.readLine();
    }

    return prepareData(fileStrings);
}

bool TableModel::prepareData(QStringList &data)
{
    for(auto i = data.begin(); i != data.end(); ++i) {
        QStringList row = (*i).split(";", QString::SkipEmptyParts);
        if(row.size() != 3) return false;

        for(auto j = row.begin(); j != row.end(); ++j) (*j) = (*j).trimmed();

        m_data.append(row);
    }

    return true;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    switch(role) {
    case COLUMN_ID:
        return m_data[index.row()][0];
        break;

    case COLUMN_NAME:
        return m_data[index.row()][1];
        break;

    case COLUMN_PHONE:
        return m_data[index.row()][2];
        break;

    default: return QVariant();
    }
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[COLUMN_ID]    = "id_role";
    roles[COLUMN_NAME]  = "name_role";
    roles[COLUMN_PHONE] = "phone_role";
    return roles;
}
