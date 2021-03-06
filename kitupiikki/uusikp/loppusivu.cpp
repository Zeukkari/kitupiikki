/*
   Copyright (C) 2017 Arto Hyvättinen

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

#include <QLabel>
#include <QVBoxLayout>
#include <QTextBrowser>

#include "loppusivu.h"
#include "uusikirjanpito.h"

LoppuSivu::LoppuSivu()
{
    setTitle("Valmista");

    QLabel *teksti = new QLabel("Kitupiikki on valmis luomaan uuden kirjanpidon.");

    ohjeBrowser = new QTextBrowser;
    ohjeBrowser->setOpenExternalLinks(true);

    QVBoxLayout *leiska = new QVBoxLayout();
    leiska->addWidget(teksti);
    leiska->addWidget(ohjeBrowser);

    setLayout(leiska);

}

void LoppuSivu::initializePage()
{
    QString polku = field("tilikartta").toString();
    QString introteksti = UusiKirjanpito::lueKtkTiedosto(polku).value("TilikarttaOhje").join("\n");

    ohjeBrowser->setHtml(introteksti);

}
