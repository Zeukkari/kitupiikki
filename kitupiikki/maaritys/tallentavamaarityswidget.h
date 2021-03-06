/*
   Copyright (C) 2018 Arto Hyvättinen

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
#ifndef TALLENTAVAMAARITYSWIDGET_H
#define TALLENTAVAMAARITYSWIDGET_H

#include "maarityswidget.h"
#include <QList>


/**
 * @brief Määrityksiä tallentavan MaaritysWidgetin kantaluokka
 *
 * Perityn widgetin rakentajassa käytettävät komponentit rekisteröidään
 * käytetyille asetusten tunnuksille rekisteroi-metodilla
 *
 * Tuetut widgetit: QLineEdit
 *
 */
class TallentavaMaaritysWidget : public MaaritysWidget
{
public:
    TallentavaMaaritysWidget(QWidget *parent = nullptr);

public:
    bool nollaa() override;
    bool tallenna() override;
    bool onkoMuokattu() override;

protected slots:
    void ilmoitaMuokattu();

protected:
    void rekisteroi(QWidget* widget, const QString& asetustunnus);

private:
    QList<QWidget*> widgetit_;


};

#endif // TALLENTAVAMAARITYSWIDGET_H
