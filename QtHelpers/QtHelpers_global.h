/* © 2012 Mirko Boehm <mirko@agile-workers.com>
 * This file is part of QtHelpers.
 *
 * QtHelpers is licensed under the LGPL version 3.0.
 */

#ifndef QTHELPERS_GLOBAL_H
#define QTHELPERS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTHELPERS_LIBRARY)
#  define QTHELPERSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTHELPERSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTHELPERS_GLOBAL_H
