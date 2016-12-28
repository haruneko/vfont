/**
 * Created by Hal@shurabaP on 2016/12/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef VFONT_META_H
#define VFONT_META_H

#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace haruneko {
namespace voicebank {

class Meta final {
    class MetaData : public QSharedData {
    public:
        MetaData() : MetaData(QString(), QString(), QString(), QString(), QString(), QString()) { }
        MetaData(
                const QString &author,
                const QString &url,
                const QString &icon,
                const QString &pathSample,
                const QString &license,
                const QString &description) :
                author(author), url(url), icon(icon), pathSample(pathSample), license(license), description(description) { }
        const QString author;
        const QString url;
        const QString icon;
        const QString pathSample;
        const QString license;
        const QString description;
    };
    QSharedDataPointer<MetaData> d;
public:
    Meta() : d(new MetaData()) { }
    Meta(
            const QString &author,
            const QString &url,
            const QString &icon,
            const QString &pathSample,
            const QString &license,
            const QString &description) :
            d(new MetaData(author, url, icon, pathSample, license, description)) { }
    Meta(const Meta &other) : d(other.d) { }
    Meta &operator=(const Meta &other) { this->d = other.d; return *this; }

    const QString &author() const { return d->author; }
    const QString &url() const { return d->url; }
    const QString &icon() const { return d->icon; }
    const QString &pathSample() const { return d->pathSample; }
    const QString &license() const { return d->license; }
    const QString &description() const { return d->description; }

    bool operator ==(const Meta &other) const {
        return this->author() == other.author() &&
                this->url() == other.url() &&
                this->icon() == other.icon() &&
                this->pathSample() == other.pathSample() &&
                this->license() == other.license() &&
                this->description() == other.description();
    }
};

}
}


#endif //VFONT_META_H
