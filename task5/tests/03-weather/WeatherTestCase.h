
#pragma once

#include <gtest/gtest.h>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
    void SetUp() {
      weather = new WeatherMock;

      // Mock1
      cpr::Response mockResponse1;
      mockResponse1.status_code = 404;
      EXPECT_CALL(*weather, Get("no_such_city")).
      WillRepeatedly(testing::Return(mockResponse1));

      // Mock2
      cpr::Response mockResponse2;
      mockResponse2.status_code = 200;
      mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": 30}}]}";
      EXPECT_CALL(*weather, Get("Yerevan")).
      WillRepeatedly(testing::Return(mockResponse2));

      // Mock3
      cpr::Response mockResponse3;
      mockResponse3.status_code = 200;
      mockResponse3.text = "{\"list\" : [{\"main\": {\"temp\": 0}}]}";
      EXPECT_CALL(*weather, Get("Moscow"))
      .WillRepeatedly(testing::Return(mockResponse3));


    }

    void TearDown() {
      delete weather;
    }
    WeatherMock *weather;
};



