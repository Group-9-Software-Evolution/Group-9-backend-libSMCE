#include "SMCE_framebuffer.hpp"
#include "SMCE_dll.hpp"
#include <iostream>

using namespace smce;

void SMCE_Framebuffer::set(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    if(!board_view.frame_buffers[m_id].exists()){ return;}
    board_view.frame_buffers[m_id].set_pixel(x,y,r,g,b);

}

int SMCE_Framebuffer::begin(std::uint16_t height, std::uint16_t width){
    const auto error = [=](const char* msg) {
        std::cerr << "ERROR: FrameBuffer::begin(" << width << height <<"): " << msg
                  << std::endl;
        return -1;
    };
    if (m_begun) {
        std::cerr << "SMCE_Framebuffer::begin: device already active" << std::endl;
        return -1;
    }
    auto fb = board_view.frame_buffers[m_id];
    if (!fb.exists())
        return error("Framebuffer does not exist");
    if (fb.direction() != smce::FrameBuffer::Direction::out)
        return error("Framebuffer not in output mode");

    fb.set_width(width);
    fb.set_height(height);

    m_begun = true;
    return 0;
}

void SMCE_Framebuffer::end(){
    if (!m_begun) {
        std::cerr << "SMCE_Framebuffer::end: device inactive" << std::endl;
        return;
    }
    auto fb = board_view.frame_buffers[m_id];
    fb.set_width(0);
    fb.set_height(0);
    fb.set_freq(0);
}

int SMCE_Framebuffer::width() {
    if (!m_begun) {
        std::cerr << "SMCE_Framebuffer::width: device inactive" << std::endl;
        return 0;
    }
    return board_view.frame_buffers[m_id].get_width();
}

int SMCE_Framebuffer::height() {
    if (!m_begun) {
        std::cerr << "SMCE_Framebuffer::height: device inactive" << std::endl;
        return 0;
    }
    return board_view.frame_buffers[m_id].get_height();
}