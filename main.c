// Moon Render: render characters using moon emoji in shell
// Copyright (C) 2020 7sDream <i@7sdre.am>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <assert.h>

#include <ft2build.h>
#include FT_FREETYPE_H

static const char* CHARS[] = {"", ""};
static const FT_ULong SCALAR_VALUES[] = {0xf113, 0xf09b};

static const char FONT_NAME[] = "Font Awesome";
static const char FONT_PATH[] = "/Users/7sdream/Library/Fonts/Font Awesome 5 Brands-Regular-400.otf";
static const FT_UInt CHAR_PIXEL_HEIGHT = 24;

static_assert(
    sizeof(CHARS) / sizeof(char*) == sizeof(SCALAR_VALUES) / sizeof(FT_ULong),
    "char and scalar value count not match"
);

static const size_t CHARS_COUNT = sizeof(CHARS) / sizeof(char*);

typedef char* GrayHintCharPair[2];

char* showGray(unsigned char left, unsigned char self, unsigned char right) {
    static const GrayHintCharPair GrayChars[] = {{"🌕", "🌕"}, {"🌖", "🌔"}, {"🌗", "🌓"}, {"🌘", "🌒"}, {"🌑", "🌑"}};
    static const size_t CharPairCount = sizeof(GrayChars) / sizeof(GrayHintCharPair);
    static double Multiplier = (double)(CharPairCount) / 256.0;

    if (self == 0) {
        return GrayChars[CharPairCount - 1][0];
    }

    size_t index = (size_t)((255 - self) * Multiplier);

    if (left < right) {
        return GrayChars[index][1];
    } else {
        return GrayChars[index][0];
    }
}

void render(FT_Face face, const char* s, FT_ULong c) {
    FT_Error error = FT_Load_Char(face, c, FT_LOAD_RENDER); // NOLINT(hicpp-signed-bitwise)

    if (error != FT_Err_Ok) {
        printf("Error when load and render character %s(%06lX), code: %d\n\n", s, c, error);
        return;
    }

    FT_GlyphSlot glyph = face->glyph;
    FT_Bitmap bitmap = glyph->bitmap;

    // printf("Left: %d\n", glyph->bitmap_left);
    // printf("Top: %d\n", glyph->bitmap_top);
    // printf("Bitmap size: %dx%d\n", bitmap.width, bitmap.rows);

    // uint32_t advanceX = glyph->advance.x;
    // uint32_t advanceY = glyph->advance.y;

    // advance value is in 26.6 frac format, convert it for print
    //
    // uint32_t advanceXInt = advanceX >> 6u;
    // uint32_t advanceXFrac = advanceX & 0x3Fu;
    // uint32_t advanceYInt = advanceY >> 6u;
    // uint32_t advanceYFrac = advanceY & 0x3Fu;

    // printf("Advance: (%u.%u, %u.%u)\n\n", advanceXInt, advanceXFrac, advanceYInt, advanceYFrac);

    for (size_t i = 0; i < bitmap.rows; i++) {
        for (size_t j = 0; j < bitmap.width; j++) {
            unsigned char left = 0, right = 0;
            size_t index = i * bitmap.width + j;
            if (j > 0) { left = bitmap.buffer[index - 1]; }
            if (j < bitmap.width - 1) { right = bitmap.buffer[index + 1]; }
            printf("%s", showGray(left, bitmap.buffer[index], right));
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    printf("Try render \"");
    for (size_t i = 0; i < CHARS_COUNT; i++) { printf("%s", CHARS[i]); }
    printf("\" use \"%s\" font\n", FONT_NAME);

    FT_Library library;
    FT_Error error = FT_Init_FreeType(&library);
    if (error != FT_Err_Ok) {
        printf("Error when loading freetype: %d\n", error);
        return -1;
    }

    FT_Face face;
    error = FT_New_Face(library, FONT_PATH, 0, &face);
    if (error != FT_Err_Ok) {
        printf("Error when loading font face: %d\n", error);
        return -2;
    }

    error = FT_Set_Pixel_Sizes(face, 0, CHAR_PIXEL_HEIGHT);
    if (error != FT_Err_Ok) {
        printf("Error when set font size: %d\n", error);
        return -3;
    }

    printf("\n");

    for (size_t i = 0; i < CHARS_COUNT; i++) {
        render(face, CHARS[i], SCALAR_VALUES[i]);
    }

    return 0;
}
