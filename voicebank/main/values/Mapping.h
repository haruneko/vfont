/**
 * Created by Hal@shurabaP on 2016/04/20.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_VOICEBANK_ROOT_MAPPING_H
#define HARUNEKO_VOICEBANK_ROOT_MAPPING_H

#include <QMap>
#include <QSharedData>
#include "values/Pronounce.h"
#include "values/Segment.h"

namespace haruneko {
namespace voicebank {

    class Mapping {
        class MappingData : public QSharedData {
        public:
            MappingData() : pronounce(), segments() { }
            MappingData(const MappingData &other) : pronounce(other.pronounce), segments(other.segments) { }
            MappingData(const Pronounce &pronounce, const QMap<QString, Segment> &segments) : pronounce(pronounce), segments(segments) { }

            const Pronounce pronounce;
            const QMap<QString, Segment> segments;
        };
        QSharedDataPointer<MappingData> d;
    public:
        Mapping() : d(new MappingData()) { }
        Mapping(const Mapping &other) : d(other.d) { }
        Mapping(const Pronounce &pronounce, const QMap<QString, Segment> &segments) : d(new MappingData(pronounce, segments)) { }

        const Pronounce &pronounce() const { return d->pronounce; }
        const QMap<QString, Segment> &segments() const { return d->segments; }
    };

}
}


#endif //HARUNEKO_VOICEBANK_ROOT_MAPPING_H
