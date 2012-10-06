/* © 2012 Mirko Boehm <mirko@agile-workers.com>
 * This file is part of QtHelpers.
 *
 * QtHelpers is licensed under the LGPL version 3.0.
 */

#ifndef QOBJECTDESCRIPTION_H
#define QOBJECTDESCRIPTION_H

namespace QtHelpers {

QString qobject_description(const QObject* object) {
    const QString address(object == 0
                          ? QObject::tr("(null)")
                          : QObject::tr("%1@%2")
                            .arg(object->metaObject()->className())
                            .arg(QString::number(ulong(object), 16).toUpper()));
    if (object && !object->objectName().isEmpty()) {
        const QString addressWithName = QObject::tr("\"%1\"[%2]").arg(object->objectName()).arg(address);
        return addressWithName;
    } else {
        return address;
    }
}

}

#endif // QOBJECTDESCRIPTION_H
