/*
* Copyright (C) 2020 ~ %YEAR% Uniontech Software Technology Co.,Ltd.
*
* Author:     shicetu <shicetu@uniontech.com>
*
* Maintainer: shicetu <shicetu@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "actiontoken.h"
#include "avcodec.h"
#include "cameradetect.h"
#include "effectproxy.h"
#include "thumbnailsbar.h"
#include "toolbar.h"
#include "videoeffect.h"
#include "videowidget.h"
#include "widgetproxy.h"
#include "set_widget.h"
#include "devnummonitor.h"

#include <QObject>
#include <DMainWindow>
#include <QPushButton>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <DTitlebar>
DWIDGET_USE_NAMESPACE
class QGridLayout;


//应用层界面通信站，与底层通信通过proxy代理类
class CMainWindow : public DMainWindow
{
    Q_OBJECT
public:
    CMainWindow(DWidget *w = nullptr);
    ~CMainWindow();


    void newPreViewByState(PRIVIEW_STATE state);
    void newNinePreview();
    void showPreviewByState(PRIVIEW_STATE state);

private:
    //Titlebar *_titlebar {nullptr};
    ThumbnailsBar   m_thumbnail;
    actionToken     m_actToken;
    avCodec         m_avCodec;
    CameraDetect    m_camDetect;
    effectproxy     m_effProxy;
    ToolBar         m_toolBar;
    videoEffect     m_videoEffect;
    videowidget     m_videoPre;
    widgetProxy     m_wgtProxy;


    QFileSystemWatcher m_fileWatcher;
    DevNumMonitor *m_devnumMonitor;

    QVector<videopreviewwidget *> m_VEffectPreview;
    void initUI();
    void initConnection();

private:


};

#endif // MAINWINDOW_H
