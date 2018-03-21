#ifndef LAYERTABLEMODEL_H
#define LAYERTABLEMODEL_H

#include <qabstracttablemodel>
#include <qstringlist>
#include <qlist>
#include <qpixmap>
#include <qimage>
#include <qicon>
#include <qdebug>
#include <qitemselectionmodel>
#include <QBrush>
#include <QStandardItem>

using LayerItem = QStandardItem;

class LayerTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    LayerTableModel(QObject *parent = 0);
    ~LayerTableModel();

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    void deleteItem(int index);

    void addItem(QString &layerName, QImage &thumbnail, bool isShow = true);

    void refreshModel();

    QModelIndex&selecttedIndex(int row);

    void setSelecttedRow(int row);

    int getSelecttedRow() const;
    QList<LayerItem> layerList;

public slots:
    void changeLayerVisibility(const QModelIndex&);

private:
//    struct LayerItem{
//        QString layerName;
//        QImage thumbnail;
//        float transparence;
//        bool isShow;
//    };

    int selectedRow;
};

#endif // LAYERTABLEMODEL_H
