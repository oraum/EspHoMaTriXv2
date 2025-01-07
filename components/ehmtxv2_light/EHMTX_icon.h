#pragma once

#include "esphome/components/animation/animation.h"

namespace esphome {
namespace ehmtx {
/**
 * @brief Class for icon handling and type/animation control
 *
 */
class EHMTX_Icon : public animation::Animation {
 protected:
  /**
   * @brief for pinppong display of animations
   *
   */
  bool counting_up;

 public:
  /**
   * @brief Construct a new ehmtx icon object
   *
   * @param data_start
   * @param width
   * @param height
   * @param animation_frame_count
   * @param type
   * @param icon_name
   * @param revers play reverse
   * @param frame_duration time per frame
   */
  explicit EHMTX_Icon(const uint8_t *data_start, int width, int height, uint32_t animation_frame_count,
                      esphome::image::ImageType type, std::string icon_name, bool revers, uint16_t frame_duration);

#ifdef USE_ESP32
  PROGMEM std::string name;
#endif
#ifdef USE_ESP8266
  std::string name;
#endif
  uint16_t frame_duration;
  void next_frame();
  bool reverse;
};
}  // namespace ehmtx
}  // namespace esphome
