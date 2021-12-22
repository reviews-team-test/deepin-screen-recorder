/*

* Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.

*

* Author:     wangcong <wangcong@uniontech.com>

*

* Maintainer: wangcong <wangcong@uniontech.com>

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

#ifndef DBUSPINSCREENSHOTSADAPTOR_H
#define DBUSPINSCREENSHOTSADAPTOR_H
#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE
/**
 * @brief  提供给外部程序调用的方法
 */
class DbusPinScreenShotsAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    //类的附加信息 可以为类的元对象定义“名称--值”
    Q_CLASSINFO("D-Bus Interface", "com.deepin.PinScreenShots")
    Q_CLASSINFO("D-Bus Introspection", ""
                "  <interface name=\"com.deepin.PinScreenShots\">\n"

                "    <method name=\"openImage\">\n"
                "      <arg direction=\"in\" type=\"ay\" name=\"openImage\"/>\n"
                "    </method>\n"

                "    <method name=\"openImageAndName\">\n"
                "      <arg direction=\"in\" type=\"ay\" name=\"images\"/>\n"
                "      <arg direction=\"in\" type=\"s\" name=\"imageName\"/>\n"
                "    </method>\n"

                "    <method name=\"openFile\">\n"
                "      <arg direction=\"in\" type=\"s\" name=\"openFile\"/>\n"
                "      <arg direction=\"out\" type=\"b\"/>\n"
                "    </method>\n"

                "  </interface>\n")

public:
    explicit DbusPinScreenShotsAdaptor(QObject *parent);
    virtual ~DbusPinScreenShotsAdaptor();

public Q_SLOTS: // METHODS
    void openImage(QByteArray images);
    void openImageAndName(QByteArray images, QString imageName);
    bool openFile(QString filePath);

Q_SIGNALS: // SIGNALS

};

#endif // DBUSPINSCREENSHOTSADAPTOR_H