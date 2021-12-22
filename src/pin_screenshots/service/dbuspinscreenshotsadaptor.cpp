#include "dbuspinscreenshotsadaptor.h"
#include <QtCore/QMetaObject>
#include <QImage>
DbusPinScreenShotsAdaptor::DbusPinScreenShotsAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

DbusPinScreenShotsAdaptor::~DbusPinScreenShotsAdaptor()
{
    // destructor
}

bool DbusPinScreenShotsAdaptor::openFile(QString filePath)
{
    qDebug() << __FUNCTION__ << __LINE__;
    QMetaObject::invokeMethod(parent(), "openFile", Q_ARG(QString, filePath));
    return true;
}


void DbusPinScreenShotsAdaptor::openImageAndName(QByteArray images, QString imageName)
{
    qDebug() << __FUNCTION__ << __LINE__;
    QByteArray data = images;
    QString tmp_data = QString::fromLatin1(data.data(), data.size());
    QByteArray srcData = QByteArray::fromBase64(tmp_data.toLatin1());
    data = qUncompress(srcData);
    QImage image;
    image.loadFromData(data);
    QMetaObject::invokeMethod(parent(), "openImageAndName", Q_ARG(QImage, image), Q_ARG(QString, imageName));
}

void DbusPinScreenShotsAdaptor::openImage(QByteArray images)
{
    qDebug() << __FUNCTION__ << __LINE__;
    QByteArray data = images;
    QString tmp_data = QString::fromLatin1(data.data(), data.size());
    QByteArray srcData = QByteArray::fromBase64(tmp_data.toLatin1());
    data = qUncompress(srcData);
    QImage image;
    image.loadFromData(data);
    QMetaObject::invokeMethod(parent(), "openImage", Q_ARG(QImage, image));
}