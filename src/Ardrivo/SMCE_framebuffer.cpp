#include "SMCE_framebuffer.hpp"
#include "SMCE_dll.hpp"
#include "SMCE/BoardView.hpp"

namespace smce {
extern BoardView board_view;
extern void maybe_init();
} // namespace smce

using namespace smce;


void SMCE_Framebuffer::set(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    if(!board_view.frame_buffers[m_id].exists()){ return;}
    board_view.frame_buffers[m_id].set_pixel(x,y,r,g,b);
}