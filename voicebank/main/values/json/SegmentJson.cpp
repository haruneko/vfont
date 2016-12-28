/**
 * Created by Hal@shurabaP on 2016/09/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#include <QHash>
#include "SegmentJson.h"

namespace haruneko {
namespace util {

QJsonValue operator << (QJsonValue &value, const haruneko::voicebank::Segment &segment) {
    QJsonObject json;
    json["path"] = QJsonValue(segment.path());
    json["begin"] = QJsonValue(segment.begin().millis());
    json["length"] = QJsonValue(segment.length().millis());
    json["temporal_position"] = QJsonValue(segment.temporalPosition().millis());
    json["front_fixed_range"] = QJsonValue(segment.frontFixedRange().millis());
    json["rear_fixed_range"] = QJsonValue(segment.rearFixedRange().millis());
    return (value = json);
}

QJsonValue operator >> (const QJsonValue &value, haruneko::voicebank::Segment &segment) {
    QJsonObject json = value.toObject();
    segment = haruneko::voicebank::Segment(
            json["path"].toString(),
            haruneko::util::Duration::millis(json["begin"].toInt()),
            haruneko::util::Duration::millis(json["length"].toInt()),
            haruneko::util::Duration::millis(json["temporal_position"].toInt()),
            haruneko::util::Duration::millis(json["front_fixed_range"].toInt()),
            haruneko::util::Duration::millis(json["rear_fixed_range"].toInt()));
    return value;
}

}
}
