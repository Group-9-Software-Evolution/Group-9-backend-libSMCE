#pragma once

#include "SMCE_dll.hpp"
#include <cstdint>

class SMCE__DLL_RT_API SMCE_Framebuffer {
  public:
    explicit SMCE_Framebuffer(int id) {
        m_id = id;
    }
    void set (int x, int y, uint8_t r, uint8_t g, uint8_t b);
    int begin (std::uint16_t width, std::uint16_t height);
    int width();
    int height();
    void end ();
  private:
    int m_id;
    bool m_begun = false;
};