/**
 * Created by Hal@shurabaP on 2016/12/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef VFONT_VOICEBANK_H
#define VFONT_VOICEBANK_H

#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>
#include "values/Meta.h"

namespace haruneko {
namespace voicebank {

class Voicebank {
    class VoicebankData : public QSharedData {
    public:
        VoicebankData() : id(), version(), pathMappings(), meta() { }
        VoicebankData(const QString &id, const QString &version, const QString &pathMappings, const Meta &meta) :
            id(id), version(version), pathMappings(pathMappings), meta(meta) { }
        VoicebankData(const VoicebankData &other) : VoicebankData(id, version, pathMappings, meta) { }

        const QString id;
        const QString version;
        const QString pathMappings;
        const Meta meta;
    };
    QSharedDataPointer<VoicebankData> d;
public:
    Voicebank() : d(new VoicebankData()) { }
    Voicebank(const QString &id, const QString &version, const QString &pathMappings, const Meta &meta) :
            d(new VoicebankData(id, version, pathMappings, meta)) { }
    Voicebank(const Voicebank &other) : d(other.d) { }
    Voicebank &operator=(const Voicebank &other) { this->d = other.d; return *this; }

    const QString &id() const { return d->id; }
    const QString &version() const { return d->version; }
    const QString &pathMappings() const { return d->pathMappings; }
    const Meta &meta() const {return d->meta; }

    bool operator==(const Voicebank &other) const {
        return this->id() == other.id() &&
               this->version() == other.version() &&
               this->pathMappings() == other.pathMappings() &&
               this->meta() == other.meta();
    }
};

}
}

#endif //VFONT_VOICEBANK_H
