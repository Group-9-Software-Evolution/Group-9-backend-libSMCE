

#include <iostream>
#include <limits>
#include "SMCE_framebuffer.hpp"
#include "SMCE_dll.hpp"
#include "SMCE/BoardView.hpp"

namespace smce {
extern BoardView board_view;
extern void maybe_init();
} // namespace smce

using namespace smce;

struct SMCE_FramebufferImpl : SMCE_Framebuffer {
    explicit SMCE_FramebufferImpl(int id) noexcept : m_id{id} {}
    const int m_id;

    FrameBuffer view() noexcept {
        maybe_init();
        return board_view.frame_buffers[m_id];
    }
};

SMCE_FramebufferImpl Frame_impl{0};
SMCE__DLL_API SMCE_Framebuffer& Framebuffer{Frame_impl};

constexpr SMCE_FramebufferImpl& upcast(SMCE_Framebuffer& obj) {
    return static_cast<SMCE_FramebufferImpl&>(obj); // NOLINT
}

void SMCE_Framebuffer::set(int x, int y, uint8_t r, uint8_t g, uint8_t b, int id) {
    board_view.frame_buffers[id].set_pixel(x,y,r,g,b);
}

