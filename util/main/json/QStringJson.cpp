/**
 * Created by Hal@shurabaP on 2016/12/10.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#include "QStringJson.h"

namespace haruneko {
namespace util {

QJsonValue operator << (QJsonValue &json, const QString &value) {
    return (json = QJsonValue(value));
}

QJsonValue operator >> (const QJsonValue &json, QString &value) {
    value = json.toString();
    return json;
}

}
}