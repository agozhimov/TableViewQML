#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QFile>
#include <QList>
#include <QStringList>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TableModel(QString path, QObject *parent = nullptr);

    bool load();

private:
    enum ColumnRole {
        COLUMN_ID = Qt::UserRole + 1,
        COLUMN_NAME,
        COLUMN_PHONE
    };

    bool prepareData(QStringList &data);

    QList<QStringList> m_data;
    QString m_filePath;

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;
};

#endif // TABLEMODEL_H
