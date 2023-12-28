#include "simple_font.h"
#include "vdisplay_driver.h"
#include "vdisplay_sprite.h"

inline volatile unsigned int BREAKPOINT __attribute__((used, section(".breakpoint")));

constexpr unsigned int DISPLAY_WIDTH_PIXELS = 192;
constexpr unsigned int DISPLAY_HEIGHT_PIXELS = 96;
constexpr unsigned int DISPLAY_COLOR_DEPTH = 1;

constexpr DisplayConfig
    display_config(DISPLAY_WIDTH_PIXELS, DISPLAY_HEIGHT_PIXELS, DISPLAY_COLOR_DEPTH);

typedef DisplayBuffers<display_config> display_buffers;

constexpr SimpleFont::SpriteType HELLO_WORLD[] = {
    SimpleFont::H,
    SimpleFont::E,
    SimpleFont::L,
    SimpleFont::L,
    SimpleFont::O,
    SimpleFont::SPACE,
    SimpleFont::W,
    SimpleFont::O,
    SimpleFont::R,
    SimpleFont::L,
    SimpleFont::D,
    SimpleFont::EXCLAMATION_MARK,
};

constexpr unsigned int GRID_X = 1;
constexpr unsigned int GRID_Y = 1;
constexpr unsigned int GRID_PADDING_X = 1;
constexpr unsigned int GRID_PADDING_Y = 1;

constexpr unsigned int GRID_WIDTH =
    (display_config.width - GRID_X) / (SimpleFont::SPRITE_WIDTH + GRID_PADDING_X);
constexpr unsigned int GRID_HEIGHT =
    (display_config.height - GRID_Y) / (SimpleFont::SPRITE_HEIGHT + GRID_PADDING_Y);

SpriteGrid<GRID_WIDTH,
           GRID_HEIGHT,
           SimpleFont::SPRITE_WIDTH,
           SimpleFont::SPRITE_HEIGHT,
           GRID_X,
           GRID_Y,
           GRID_PADDING_X,
           GRID_PADDING_Y>
    sprite_grid;

int main() {
    display_frame_buffer<display_config>(display_buffers::a);

    for (const auto &sprite : HELLO_WORLD) {
        draw_sprite<display_config>(sprite_grid, sprite, display_buffers::a);
    }
}
