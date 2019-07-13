/*
   Copyright (C) 2019 Arto Hyvättinen

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef TOSITELIITTEET_H
#define TOSITELIITTEET_H

#include <QAbstractListModel>

class TositeLiitteet : public QAbstractListModel
{
    Q_OBJECT

protected:
    class TositeLiite
    {
    public:
        TositeLiite(int id=0, const QString& nimi = QString(),
                    const QByteArray& sisalto = QByteArray());

        int getLiiteId() const;
        void setLiiteId(int value);

        QString getNimi() const;
        void setNimi(const QString &value);

    protected:
        int liiteId_ = 0;
        QString nimi_;
        QByteArray sisalto_;
    };

public:
    explicit TositeLiitteet(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void lataa(QVariantList data);

    bool lisaa(const QByteArray& liite, const QString& nimi);
    bool lisaaTiedosto(const QString& polku);

    bool canDropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const override;
    bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex &parent) override;

    int tallennettaviaLiitteita() const;

private:
    QList<TositeLiite> liitteet_;
    QList<int> poistetut_;

    int tallennuksessa_ = -1;

};

#endif // TOSITELIITTEET_H