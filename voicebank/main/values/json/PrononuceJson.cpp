/**
 * Created by Hal@shurabaP on 2016/12/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#include "PrononuceJson.h"

namespace haruneko {
namespace util {

    QJsonValue operator << (QJsonValue &value, const haruneko::voicebank::Pronounce &pronounce) {
        QJsonObject json;
        json["before"] = QJsonValue(pronounce.before());
        json["this"] = QJsonValue(pronounce._this());
        json["after"] = QJsonValue(pronounce.after());
        return value = json;
    }

    QJsonValue operator >> (const QJsonValue &value, haruneko::voicebank::Pronounce &pronounce) {
        QJsonObject json(value.toObject());
        pronounce = haruneko::voicebank::Pronounce(
                json["before"].toString(),
                json["this"].toString(),
                json["after"].toString());
        return value;
    }
}
}