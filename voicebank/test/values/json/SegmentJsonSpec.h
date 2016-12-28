/**
 * Created by Hal@shurabaP on 2016/04/24.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2016 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_VOICEBANK_ROOT_SEGMENTJSONSPEC_H
#define HARUNEKO_VOICEBANK_ROOT_SEGMENTJSONSPEC_H

#include <QtTest/QtTest>
#include <QJsonDocument>

#include "MultipleTest.h"
#include "values/Segment.h"
#include "values/json/SegmentJson.h"
#include "json/Json.h"

using namespace haruneko::util;
using namespace haruneko::voicebank;

class SegmentJsonSpec : public QObject {
Q_OBJECT
    QString okString = QString(
            "{\n"
            "  \"path\": \"akasatana.wav\",\n"
            "  \"begin\": 500,\n"
            "  \"length\": 500,\n"
            "  \"temporal_position\" : 100,\n"
            "  \"front_fixed_range\" : 100,\n"
            "  \"rear_fixed_range\" : 100\n"
            "}");
    QJsonDocument okJson = QJsonDocument::fromJson(okString.toLocal8Bit());
    Segment okSegment = Segment(QString("akasatana.wav"), Duration::millis(500), Duration::millis(500), Duration::millis(100), Duration::millis(100), Duration::millis(100));
private slots:
    void toJson_should_return_the_expected_JSON() {
        auto v = Json::toJson(okSegment);
        QCOMPARE(QJsonDocument(v.toObject()), okJson);
    };
    void fromJson_should_return_the_expected_Segment() {
        QCOMPARE(Json::fromJson<Segment>(QJsonValue(okJson.object())).get(), okSegment);
    }
    void fromJson_should_return_the_expected_Segment_even_if_extra_key_exists() {
        QString extraString = QString(
                "{\n"
                "  \"path\": \"akasatana.wav\",\n"
                "  \"begin\": 500,\n"
                "  \"length\": 500,\n"
                "  \"temporal_position\" : 100,\n"
                "  \"front_fixed_range\" : 100,\n"
                "  \"rear_fixed_range\" : 100,\n"
                "  \"extra\": \"key\""
                "}");
        QJsonValue v = QJsonDocument::fromJson(extraString.toLocal8Bit()).object();
        QCOMPARE(Json::fromJson<Segment>(v).get(), okSegment);
    }
    void fromJson_should_throw_JsonValidationErrorException_when_an_empty_JSON_given() {
        QJsonValue v = QJsonDocument::fromJson(QString("{}").toLocal8Bit()).object();
        QVERIFY_EXCEPTION_THROWN(Json::fromJson<Segment>(v).get(), JsonValidationErrorException);
    }
};

DECLARE_TEST(SegmentJsonSpec);

#endif //HARUNEKO_VOICEBANK_ROOT_SEGMENTJSONSPEC_H
