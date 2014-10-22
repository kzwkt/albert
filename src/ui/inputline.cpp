// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "albert.h"
#include "inputline.h"
#include "settingsdialog.h"
#include <QString>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QResizeEvent>

/**************************************************************************/
InputLine::InputLine(QWidget *parent) :
	QLineEdit(parent)
{
	setObjectName(QString::fromLocal8Bit("inputline"));
	setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

	_settingsButton = new SettingsButton(this);
	_settingsButton->setFocusPolicy(Qt::NoFocus);
}

/**************************************************************************/
void InputLine::focusOutEvent(QFocusEvent *)
{
	gAlbertWidget->toggleVisibility();
}

/**************************************************************************/
void InputLine::resizeEvent(QResizeEvent *event)
{
	_settingsButton->move(event->size().width()-_settingsButton->width(),0);
}

/**************************************************************************/
void InputLine::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Comma:
		SettingsDialog::instance()->show();
		return;

	case Qt::Key_F4:
		qApp->quit();
		return;

	case Qt::Key_Escape:
		window()->hide();
		return;
	}
	QLineEdit::keyPressEvent(event);
}
