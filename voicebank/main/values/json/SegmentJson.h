/**
 * Created by Hal@shurabaP on 2016/04/19.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_VOICEBANK_SEGMENTJSON_H
#define HARUNEKO_VOICEBANK_SEGMENTJSON_H

#include <QJsonObject>
#include <QJsonValue>
#include <json/JsonValidator.h>

#include "json/QStringJson.h"
#include "json/QIntJson.h"
#include "values/Segment.h"

namespace haruneko {
namespace util {
    template<> class JsonValidator<voicebank::Segment> {
    public:
        void validate(const QJsonValue &value) const throw(const JsonValidationErrorException &) {
            if(!value.isObject()) {
                throw JsonValidationErrorException("The JSON value is expected as Object, but it's not.");
            }
            QJsonObject json = value.toObject();
            QStringValidator.validate(json["path"]);
            IntValidator.validate(json["begin"]);
            IntValidator.validate(json["length"]);
            IntValidator.validate(json["temporal_position"]);
            IntValidator.validate(json["front_fixed_range"]);
            IntValidator.validate(json["rear_fixed_range"]);
        }
    };
    extern QJsonValue operator << (QJsonValue &value, const haruneko::voicebank::Segment &segment);
    extern QJsonValue operator >> (const QJsonValue &value, haruneko::voicebank::Segment &segment);
}
}

#endif //HARUNEKO_VOICEBANK_SEGMENTJSON_H
