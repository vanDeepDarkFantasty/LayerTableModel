#include "layertablemodel.h"

LayerTableModel::LayerTableModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    QImage image("qrc:/TIM图片20180319172005.png");

    layerList.reserve(3);

    selectedRow = 0;

    for(int i = 0; i < 3; ++i){
    addItem(QString(), image, true);
    }
}

LayerTableModel::~LayerTableModel()
{
}

QVariant LayerTableModel::data(const QModelIndex &index, int role = Qt::BackgroundColorRole) const
{
    if(!index.isValid())
        return QVariant();
    int column = index.column();

//    if(column == 0)
//    {
////        if(role ==  Qt::CheckStateRole)
////        {
////            return layerList.at(index.row()).isShow ? Qt::Checked : Qt::Unchecked;
////        }
//        if(role == Qt::SizeHintRole)
//        {
//            return QSize(20,50);
//        }
//    }
//    else
//    {
        qDebug() << "data";
        if(role == Qt::BackgroundRole)
        {qDebug() << "f";
                return QBrush(QColor(0x40, 0x40, 0x40));
        }
        if(role == Qt::EditRole)
        {qDebug() << "a";
            return QVariant(layerList.at(index.row()).text());
        }
        if(role == Qt::DisplayRole)
        {qDebug() << "b";
            return QVariant(layerList.at(index.row()).text());
        }
        if(role == Qt::DecorationRole)
        {qDebug() << "c";
            if(layerList.at(index.row()).icon().isNull())
            {
                return layerList.at(index.row()).icon();
            }else
            {
                QImage image = qvariant_cast<QImage>(layerList.at(index.row()).icon());
                QPixmap(QPixmap::fromImage(image).scaledToHeight(40));
                layerList.at(index.row()).icon() = qvariant_cast<QIcon>(image);
                return layerList.at(index.row()).icon();
            }
        }
        if(role == Qt::SizeHintRole)
        {qDebug() << "d";
            return QSize(200,50);
        }
        if(role == Qt::TextAlignmentRole)
        {qDebug() << "e";
            return int(Qt::AlignVCenter);
        }
//    }
    return QVariant();
}

int LayerTableModel::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid() && parent.column() != 0)? 0 : layerList.size();
}

int LayerTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant LayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
        return QString::number(section);
    //if(role == Qt::DecorationRole)
        //return QVariant::fromValue(services);
    return QAbstractItemModel::headerData(section, orientation, role);
}

Qt::ItemFlags LayerTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return 0;
//    if(index.column() == 0)
//        return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

bool LayerTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    if(role == Qt::CheckStateRole && value.type() == QVariant::Bool)
    {
        layerList[index.row()].setCheckable(value.toBool());
        emit(dataChanged(index,index));
        return true;
    }

    if(role == Qt::EditRole /*&& index.column() == 0*/)
    {
        layerList[index.row()].text() = value.toString();
        emit(dataChanged(index, index));
        return true;
    }

//    if(role == Qt::BackgroundColorRole)
//    {

//    }
    return false;;
}

void LayerTableModel::changeLayerVisibility(const QModelIndex& index)
{
//    if(index.isValid()&&index.column() == 0)
//    {
//        setData(index,!(layerList.at(index.row()).isShow), Qt::CheckStateRole);
//    }
}

void LayerTableModel::deleteItem(int index)
{
    QList<LayerItem>::iterator it = layerList.begin();
    layerList.erase(it + index);
}

void LayerTableModel::addItem(QString &name, QImage &thumb, bool show)
{
    LayerItem *item = new LayerItem;
    if(name.size() == 0){
        item->text() = QString("Layer") + QString::number(layerList.size());
    }
    else{
        item->text() = name;
    }
    item->setCheckable(show);
    item->icon() = QIcon(QPixmap(QPixmap::fromImage(thumb)));
    layerList.append(*item);

    //this->insertRow()
    //emit(dataChanged(index, index));

    qDebug() << layerList.size();

    //emit(dataChanged(index, index));
    //this->insertRow(rowCount(QModelIndex()));
}

QModelIndex& LayerTableModel::selecttedIndex(int row)
{
    return this->createIndex(row,1);
}

void LayerTableModel::setSelecttedRow(int row)
{
    selectedRow = row;
}

int LayerTableModel::getSelecttedRow() const
{
    return selectedRow;
}

void LayerTableModel::refreshModel()
{

}


