/*
 * sqlhelper.h
 *
 * Copyright (C) 2009 Christoph Pfister <christophpfister@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SQLHELPER_H
#define SQLHELPER_H

#include <QSqlDatabase>
#include <QTimer>

class SqlHelper : public QObject
{
	Q_OBJECT
private:
	SqlHelper();
public:
	~SqlHelper();

	static bool createInstance();
	static SqlHelper *getInstance();

	QSqlQuery prepare(const QString &statement);
	QSqlQuery exec(const QString &statement);
	void exec(QSqlQuery &query);

	void requestSubmission(QObject *object);

public slots:
	void collectSubmissions();

private:
	static void deleteInstance();
	static SqlHelper *instance;

	QSqlDatabase database;
	QTimer timer;
	QList<QObject *> objects;
};

#endif /* SQLHELPER_H */
