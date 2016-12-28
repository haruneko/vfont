/**
 * Created by Hal@shurabaP on 2016/04/20.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_VOICEBANK_ROOT_MAPPING_H
#define HARUNEKO_VOICEBANK_ROOT_MAPPING_H

#include <QList>
#include <QSharedData>
#include "values/Pronounce.h"
#include "values/Range.h"

namespace haruneko {
namespace voicebank {

    class Mapping final {
        class MappingData : public QSharedData {
        public:
            MappingData() : pronounce(), ranges() { }
            MappingData(const MappingData &other) : pronounce(other.pronounce), ranges(other.ranges) { }
            MappingData(const Pronounce &pronounce, const QList<Range> &ranges) : pronounce(pronounce), ranges(ranges) { }

            const Pronounce pronounce;
            const QList<Range> ranges;
        };
        QSharedDataPointer<MappingData> d;
    public:
        Mapping() : d(new MappingData()) { }
        Mapping(const Mapping &other) : d(other.d) { }
        Mapping(const Pronounce &pronounce, const QList<Range> &ranges) : d(new MappingData(pronounce, ranges)) { }

        const Pronounce &pronounce() const { return d->pronounce; }
        const QList<Range> &ranges() const { return d->ranges; }
    };

}
}


#endif //HARUNEKO_VOICEBANK_ROOT_MAPPING_H
