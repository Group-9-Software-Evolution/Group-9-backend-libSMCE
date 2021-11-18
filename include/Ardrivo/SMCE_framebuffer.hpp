#include "SMCE_dll.hpp"


struct SMCE_FramebufferImpl;
struct SMCE__DLL_RT_API SMCE_Framebuffer {
    void set (int x, int y, uint8_t r, uint8_t g, uint8_t b, int id);
  private:
    friend SMCE_FramebufferImpl;
};

extern SMCE__DLL_RT_API SMCE_Framebuffer& Serial;