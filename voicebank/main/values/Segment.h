/**
 * Created by Hal@shurabaP on 2016/02/21.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_VOICEBANK_ROOT_SEGMENT_H
#define HARUNEKO_VOICEBANK_ROOT_SEGMENT_H

#include <QSharedData>
#include <QString>
#include "util/Duration.h"

namespace haruneko {
namespace voicebank {

    class Segment {
        class SegmentData : public QSharedData {
        public:
            SegmentData(
                const QString &path,
                const haruneko::util::Duration begin,
                const haruneko::util::Duration length,
                const haruneko::util::Duration temporalPosition,
                const haruneko::util::Duration frontFixedRange,
                const haruneko::util::Duration rearFixedRange) :
                    path(path),
                    begin(begin),
                    length(length),
                    temporalPosition(temporalPosition),
                    frontFixedRange(frontFixedRange),
                    rearFixedRange(rearFixedRange) { }
            explicit SegmentData() :
                    SegmentData(
                            QString(),
                            haruneko::util::Duration(0),
                            haruneko::util::Duration(0),
                            haruneko::util::Duration(0),
                            haruneko::util::Duration(0),
                            haruneko::util::Duration(0)) { }
            SegmentData(const SegmentData &d) :
                    SegmentData(d.path, d.begin, d.length, d.temporalPosition, d.frontFixedRange, d.rearFixedRange) { }
            const QString path;
            const haruneko::util::Duration begin;
            const haruneko::util::Duration length;
            const haruneko::util::Duration temporalPosition;
            const haruneko::util::Duration frontFixedRange;
            const haruneko::util::Duration rearFixedRange;
        };
        QSharedDataPointer<SegmentData> d;
    public:
        Segment() : Segment(QSharedDataPointer<SegmentData>(new SegmentData())) { }
        Segment(const Segment &other) : Segment(other.d) { }
        Segment(
                const QString &path,
                const haruneko::util::Duration begin,
                const haruneko::util::Duration length,
                const haruneko::util::Duration temporalPosition,
                const haruneko::util::Duration frontFixedRange,
                const haruneko::util::Duration rearFixedRange) :
                d(QSharedDataPointer<SegmentData>(new SegmentData(path, begin, length, temporalPosition, frontFixedRange, rearFixedRange))) { }

        Segment &operator = (const Segment &other) { this->d = other.d; return *this; }
        bool operator == (const Segment &o) const {
            return path() == o.path() &&
                   begin() == o.begin() &&
                   length() == o.length() &&
                   temporalPosition() == o.temporalPosition() &&
                   frontFixedRange() == o.frontFixedRange() &&
                   rearFixedRange() == o.frontFixedRange();
        }
        const QString &path() const { return d->path; }
        const haruneko::util::Duration begin() const { return d->begin; }
        const haruneko::util::Duration length() const { return d->length; }
        const haruneko::util::Duration temporalPosition() const { return d->temporalPosition; }
        const haruneko::util::Duration frontFixedRange() const { return d->frontFixedRange; }
        const haruneko::util::Duration rearFixedRange() const { return d->rearFixedRange; }
    private:
        explicit Segment(const QSharedDataPointer<SegmentData> &d) : d(d) { }
    };

}
}

#endif //HARUNEKO_VOICEBANK_ROOT_SEGMENT_H
