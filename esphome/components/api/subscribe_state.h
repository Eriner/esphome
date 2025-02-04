#pragma once

#include "esphome/core/component.h"
#include "esphome/core/controller.h"
#include "esphome/core/defines.h"
#include "util.h"

namespace esphome {
namespace api {

class APIConnection;

class InitialStateIterator : public ComponentIterator {
 public:
  InitialStateIterator(APIServer *server, APIConnection *client);
#ifdef USE_BINARY_SENSOR
  bool on_binary_sensor(binary_sensor::BinarySensor *binary_sensor) override;
#endif
#ifdef USE_COVER
  bool on_cover(cover::Cover *cover) override;
#endif
#ifdef USE_FAN
  bool on_fan(fan::Fan *fan) override;
#endif
#ifdef USE_LIGHT
  bool on_light(light::LightState *light) override;
#endif
#ifdef USE_SENSOR
  bool on_sensor(sensor::Sensor *sensor) override;
#endif
#ifdef USE_SWITCH
  bool on_switch(switch_::Switch *a_switch) override;
#endif
#ifdef USE_BUTTON
  bool on_button(button::Button *button) override { return true; };
#endif
#ifdef USE_TEXT_SENSOR
  bool on_text_sensor(text_sensor::TextSensor *text_sensor) override;
#endif
#ifdef USE_CLIMATE
  bool on_climate(climate::Climate *climate) override;
#endif
#ifdef USE_NUMBER
  bool on_number(number::Number *number) override;
#endif
#ifdef USE_SELECT
  bool on_select(select::Select *select) override;
#endif
 protected:
  APIConnection *client_;
};

}  // namespace api
}  // namespace esphome

#include "api_server.h"
