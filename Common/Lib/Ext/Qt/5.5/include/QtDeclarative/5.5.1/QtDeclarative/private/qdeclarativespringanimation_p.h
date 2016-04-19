/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDECLARATIVESPRINGANIMATION_H
#define QDECLARATIVESPRINGANIMATION_H

#include <qdeclarative.h>
#include "private/qdeclarativeanimation_p.h"

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

QT_MODULE(Declarative)

class QDeclarativeSpringAnimationPrivate;
class Q_AUTOTEST_EXPORT QDeclarativeSpringAnimation : public QDeclarativeNumberAnimation
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QDeclarativeSpringAnimation)
    Q_INTERFACES(QDeclarativePropertyValueSource)

    Q_PROPERTY(qreal velocity READ velocity WRITE setVelocity)
    Q_PROPERTY(qreal spring READ spring WRITE setSpring)
    Q_PROPERTY(qreal damping READ damping WRITE setDamping)
    Q_PROPERTY(qreal epsilon READ epsilon WRITE setEpsilon)
    Q_PROPERTY(qreal modulus READ modulus WRITE setModulus NOTIFY modulusChanged)
    Q_PROPERTY(qreal mass READ mass WRITE setMass NOTIFY massChanged)

public:
    QDeclarativeSpringAnimation(QObject *parent=0);
    ~QDeclarativeSpringAnimation();

    qreal velocity() const;
    void setVelocity(qreal velocity);

    qreal spring() const;
    void setSpring(qreal spring);

    qreal damping() const;
    void setDamping(qreal damping);

    qreal epsilon() const;
    void setEpsilon(qreal epsilon);

    qreal mass() const;
    void setMass(qreal modulus);

    qreal modulus() const;
    void setModulus(qreal modulus);

    virtual void transition(QDeclarativeStateActions &actions,
                            QDeclarativeProperties &modified,
                            TransitionDirection direction);

protected:
    virtual QAbstractAnimation *qtAnimation();

Q_SIGNALS:
    void modulusChanged();
    void massChanged();
    void syncChanged();
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeSpringAnimation)

#endif // QDECLARATIVESPRINGANIMATION_H
