/**
 * Created by Hal@shurabaP on 2016/12/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef VFONT_PRONONUCEJSON_H
#define VFONT_PRONONUCEJSON_H

#include <QJsonObject>
#include <QJsonValue>
#include <json/JsonValidator.h>

#include "json/QStringJson.h"
#include "values/Pronounce.h"

namespace haruneko {
    namespace util {
        template<> class JsonValidator<voicebank::Pronounce> {
        public:
            void validate(const QJsonValue &value) const throw(const JsonValidationErrorException &) {
                if(!value.isObject()) {
                    throw JsonValidationErrorException("The JSON value is expected as Object, but it's not.");
                }
                QJsonObject json = value.toObject();
                QStringValidator.validate(json["before"]);
                QStringValidator.validate(json["this"]);
                QStringValidator.validate(json["after"]);
            }
        };
        extern QJsonValue operator << (QJsonValue &value, const haruneko::voicebank::Pronounce &pronounce);
        extern QJsonValue operator >> (const QJsonValue &value, haruneko::voicebank::Pronounce &pronounce);
    }
}


#endif //VFONT_PRONONUCEJSON_H
