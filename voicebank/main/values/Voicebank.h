/**
 * Created by Hal@shurabaP on 2016/12/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef VFONT_VOICEBANK_H
#define VFONT_VOICEBANK_H

#include <QMap>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace haruneko {
namespace voicebank {

class Voicebank {
    class VoicebankData : public QSharedData {
    public:
        VoicebankData() : id(), version(), pathMappings(), pathsMetas() { }
        VoicebankData(const QString &id, const QString &version, const QString &pathMappings, const QMap<QString, QString> &pathsMetas) :
            id(id), version(version), pathMappings(pathMappings), pathsMetas(pathsMetas) { }
        VoicebankData(const VoicebankData &other) : VoicebankData(id, version, pathMappings, pathsMetas) { }

        const QString id;
        const QString version;
        const QString pathMappings;
        // TODO: make it sure that keys format should be ISO 639
        const QMap<QString, QString> pathsMetas;
    };
    QSharedDataPointer<VoicebankData> d;
public:
    Voicebank() : d(new VoicebankData()) { }
    Voicebank(const QString &id, const QString &version, const QString &pathMappings, const QMap<QString, QString> &pathsMetas) :
            d(new VoicebankData(id, version, pathMappings, pathsMetas)) { }
    Voicebank(const Voicebank &other) : d(other.d) { }
    Voicebank &operator=(const Voicebank &other) { this->d = other.d; return *this; }

    const QString &id() const { return d->id; }
    const QString &version() const { return d->version; }
    const QString &pathMappings() const { return d->pathMappings; }
    const QMap<QString, QString> &pathsMetas() const {return d->pathsMetas; }

    bool operator==(const Voicebank &other) const {
        return this->id() == other.id() &&
               this->version() == other.version() &&
               this->pathMappings() == other.pathMappings() &&
               this->pathsMetas() == other.pathsMetas();
    }
};

}
}

#endif //VFONT_VOICEBANK_H
