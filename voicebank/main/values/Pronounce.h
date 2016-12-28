/**
 * Created by Hal@shurabaP on 2016/04/19.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_VOICEBANK_ROOT_PRONOUNCE_H
#define HARUNEKO_VOICEBANK_ROOT_PRONOUNCE_H

#include <QString>
#include <QSharedData>

namespace haruneko {
namespace voicebank {
    class Pronounce {
        class PronounceData : public QSharedData {
        public:
            PronounceData() : PronounceData(QString(), QString(), QString()) { }
            explicit PronounceData(const PronounceData &other) : PronounceData(other.before, other.value, other.after) { }
            PronounceData(const QString &before, const QString &value, const QString &after) :
                    before(before), value(value), after(after) { }
            const QString before;
            const QString value;
            const QString after;
        };
        QSharedDataPointer<PronounceData> d;
    public:
        Pronounce() : Pronounce("" , "", "") { }
        Pronounce(const Pronounce &other) : d(other.d) { }
        Pronounce(const QString &before, const QString &value, const QString &after) :
                d(new PronounceData(before, value, after)) { }

        bool operator ==(const Pronounce &other) const { return before() == other.before() && value() == other.value() && after() == other.after(); }
        Pronounce operator = (const Pronounce &other) { this->d = other.d; return *this; }

        const QString &before() const { return d->before; }
        const QString &value() const { return d->value; }
        const QString &after() const { return d->after; }

    private:
        explicit Pronounce(const QSharedDataPointer<PronounceData> &d) : d(d) { }
    };
}
}

#endif //HARUNEKO_VOICEBANK_ROOT_PRONOUNCE_H
