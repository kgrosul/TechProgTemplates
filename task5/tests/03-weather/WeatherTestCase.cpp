//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"


TEST_F(WeatherTestCase, SetApiKeyTest) {
  ASSERT_NO_THROW(weather->SetApiKey("my_api_key"));
}

TEST_F(WeatherTestCase, InvalidCityTest) {
  ASSERT_THROW(weather->GetResponseForCity("no_such_city"),
               std::invalid_argument);
}
TEST_F(WeatherTestCase, GetTemperatureTest) {
  ASSERT_EQ(weather->GetTemperature("Moscow"), 0);
}

TEST_F(WeatherTestCase, GetResponseForCityTest) {
  auto cityInfo = weather->GetResponseForCity("Yerevan");
  auto answer = json::parse("{\"list\" : [{\"main\": {\"temp\": 30}}]}");
  ASSERT_EQ(cityInfo, answer);
}


TEST_F(WeatherTestCase, FindDiffBetweenTwoCitiesTest) {
  ASSERT_EQ(weather->FindDiffBetweenTwoCities("Moscow", "Yerevan"), -30);
  ASSERT_EQ(weather->FindDiffBetweenTwoCities("Yerevan", "Moscow"), 30);
}

TEST_F(WeatherTestCase, GetDifferenceStringTest) {
  std::string answer1 = "Weather in Yerevan is warmer than in Moscow by 30 degrees";
  std::string answer2 = "Weather in Moscow is colder than in Yerevan by 30 degrees";
  ASSERT_EQ(weather->GetDifferenceString("Yerevan", "Moscow"), answer1);
  ASSERT_EQ(weather->GetDifferenceString("Moscow", "Yerevan"), answer2);
}
