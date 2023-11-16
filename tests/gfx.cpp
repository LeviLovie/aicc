#include <gtest/gtest.h>
#include "../src/gfx/gfx.hpp"

TEST(GFX, DefaultStyleInitializer) {
    GFX::GraphicsStyle* style = new GFX::GraphicsStyle();
    ASSERT_EQ(style->FreeCell, '.');
    ASSERT_EQ(style->OurCell, '#');
    ASSERT_EQ(style->TheirCell, '#');
    ASSERT_EQ(style->MustPutCell, '!');
    ASSERT_EQ(style->FreeColor, "\x1b[37m");
    ASSERT_EQ(style->TheirColor, "\x1b[34m");
    ASSERT_EQ(style->TheirThreeColor, "\x1b[35m");
    ASSERT_EQ(style->TheirFourColor, "\x1b[31m");
    ASSERT_EQ(style->MustPutColor, "\x1b[33m");
    ASSERT_EQ(style->OurColor, "\x1b[32m");
}
