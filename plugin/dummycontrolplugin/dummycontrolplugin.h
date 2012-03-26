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
 * \file dummycontrolplugin.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef DUMMYCONTROLPLUGIN_H
#define DUMMYCONTROLPLUGIN_H

#include <QObject>
#include "plugininterface.h"
#include "form.h"

#define DUMMY_CONTROL_PLUGIN_VERSION "1.0.0"

class DummyControlPlugin : public QObject, QDLTPluginInterface, QDltPluginViewerInterface, QDltPluginControlInterface
{
    Q_OBJECT
    Q_INTERFACES(QDLTPluginInterface)
    Q_INTERFACES(QDltPluginViewerInterface)
    Q_INTERFACES(QDltPluginControlInterface)

public:
    DummyControlPlugin();
    ~DummyControlPlugin();

    /* QDLTPluginInterface interface */
    QString name();
    QString pluginVersion();
    QString pluginInterfaceVersion();
    QString description();
    QString error();
    bool loadConfig(QString filename);
    bool saveConfig(QString filename);
    QStringList infoConfig();

    /* QDltPluginViewerInterface */
    QWidget* initViewer();
    bool initFile(QDltFile *file);
    void updateFile();
    void selectedIdxMsg(int index);

    /* QDltPluginControlInterface */
    bool initControl(QDltControl *control);
    bool initConnections(QStringList list);
    bool controlMsg(int index, QDltMsg &msg);

    /* internal variables */
    Form *form;
    int counterMessages;
    int counterNonVerboseMessages;
    int counterVerboseMessages;

    void show(bool value);

    void updateCounters(int start,int end);

    QDltControl *dltControl;

private:
    QDltFile *dltFile;
    QString errorText;
};

#endif // DUMMYCONTROLPLUGIN_H
