/**
 * Created by Hal@shurabaP on 2016/12/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef VFONT_RANGE_H
#define VFONT_RANGE_H

#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace haruneko {
namespace voicebank {

class Range final {
public:
    class Point final {
        Point() : Point(0, 0) { }
    public:
        Point(const int &velocity, const int &note) : velocity(velocity), note(note) { }
        Point(const Point &other) : Point(other.velocity, other.note) { }
        const int velocity;
        const int note;
        bool operator ==(const Point &other) const {
            return this->velocity == other.velocity && this->note == other.note;
        }
        bool operator <=(const Point &other) const {
            return  this->velocity <= other.velocity && this->note <= other.note;
        }
        friend class Range;
    };
private:
    class RangeData : public QSharedData {
    public:
        RangeData() : RangeData(QString(""), Point(), Point()) { }
        RangeData(const QString &segmentPath, const Point &begin, const Point &end) :
                segmentPath(segmentPath), begin(begin), end(end) { }
        const QString segmentPath;
        const Point begin;
        const Point end;
    };
    QSharedDataPointer<RangeData> d;
public:
    Range(const QString &segmentPath, const Point &begin, const Point &end) :
            d(new RangeData(segmentPath, begin, end)) { }
    Range(const Range &other) : d(other.d) { }
    Range() : Range("", Point(), Point()) { }

    bool operator ==(const Range &other) const {
        return this->segmentPath() == other.segmentPath() &&
               this->begin() == other.begin() &&
               this->end() == other.end();
    }

    const QString &segmentPath() const { return d->segmentPath; }
    const Point &begin() const { return d->begin; }
    const Point &end() const { return d->end; }
};

}
}


#endif //VFONT_RANGE_H
