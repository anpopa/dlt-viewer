/**
 * @licence app begin@
 * Copyright (C) 2011-2012  BMW AG
 *
 * This file is part of GENIVI Project Dlt Viewer.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file optmanager.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef OPTMANAGER_H
#define OPTMANAGER_H

#include <QStringList>

class OptManager
{
public:
    static OptManager* getInstance();
    void printUsage();
    void parse(QStringList *opt);

    bool isProjectFile();
    bool isLogFile();
    bool isFilterFile();
    bool isConvert();
    bool isPlugin();

    QString getProjectFile();
    QString getLogFile();
    QString getFilterFile();
    QString getConvertSourceFile();
    QString getConvertDestFile();

private:
    OptManager();
    OptManager(OptManager const&);
    static OptManager *instance;

    bool project;
    bool log;
    bool filter;
    bool convert;
    bool plugin;
    QString projectFile;
    QString logFile;
    QString filterFile;
    QString convertSourceFile;
    QString convertDestFile;
};

#endif // OPTMANAGER_H
