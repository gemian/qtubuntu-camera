/*
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtTest/QtTest>
#include <QSignalSpy>

#include "aalcameraservice.h"

#define private public
#include "aalcamerazoomcontrol.h"

class tst_AalCameraZoomControl : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();

    void zoomTo();

private:
    AalCameraZoomControl *m_zoomControl;
    AalCameraService *m_service;
};

void tst_AalCameraZoomControl::initTestCase()
{
    m_service = new AalCameraService();
    m_zoomControl = m_service->zoomControl();
}

void tst_AalCameraZoomControl::cleanupTestCase()
{
    delete m_service;
}

void tst_AalCameraZoomControl::zoomTo()
{
    QSignalSpy spy(m_zoomControl, SIGNAL(currentDigitalZoomChanged(qreal)));

    int zoom = 3.0;
    m_zoomControl->zoomTo(0.0, zoom);
    QCOMPARE(m_zoomControl->currentDigitalZoom(), 0.0);
    QCOMPARE(spy.count(), 0);

    m_service->connectCamera();
    zoom = 3.0;
    m_zoomControl->zoomTo(0.0, zoom);
    QCOMPARE(m_zoomControl->currentDigitalZoom(), 3.0);
    QCOMPARE(spy.count(), 1);

    m_zoomControl->resetZoom();
    QCOMPARE(m_zoomControl->currentDigitalZoom(), 0.0);
    QCOMPARE(spy.count(), 2);
}

QTEST_GUILESS_MAIN(tst_AalCameraZoomControl)

#include "tst_aalcamerazoomcontrol.moc"
