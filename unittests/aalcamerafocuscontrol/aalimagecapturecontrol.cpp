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

#include "aalimagecapturecontrol.h"

#include <hybris/camera/camera_compatibility_layer.h>
#include <hybris/camera/camera_compatibility_layer_capabilities.h>

AalImageCaptureControl::AalImageCaptureControl(AalCameraService *service, QObject *parent)
    : QCameraImageCaptureControl(parent)
{
    Q_UNUSED(service);
}

AalImageCaptureControl::~AalImageCaptureControl()
{
}

int AalImageCaptureControl::capture(const QString &fileName)
{
    Q_UNUSED(fileName);
    return 0;
}

void AalImageCaptureControl::cancelCapture()
{
}

bool AalImageCaptureControl::isReadyForCapture() const
{
    return true;
}

void AalImageCaptureControl::init(CameraControl *control, CameraControlListener *listener)
{
    Q_UNUSED(control);
    Q_UNUSED(listener);
}

void AalImageCaptureControl::setReady(bool ready)
{
    Q_UNUSED(ready);
}

void AalImageCaptureControl::shutter()
{
}

void AalImageCaptureControl::onImageFileSaved()
{
}

void AalImageCaptureControl::saveJpeg(const QByteArray& data)
{
    Q_UNUSED(data);
}

