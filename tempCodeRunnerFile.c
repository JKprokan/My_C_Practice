#include    "cglec.h"
#define WIDTH   400
#define HEIGHT  400

int main(void)
{
    unsigned char data[WIDTH][HEIGHT];

    Image img = { (unsigned char*) data, WIDTH, HEIGHT };

    CglSetAll(img, 0);                  // imgをグレイレベル0でクリアする
    int x, y;

    for (y = 0; y < 200; y++)
    {
        for (x = 0; x < 200; x++)
            data[x][y] = 0;           // グレイレベル255(白)の四角形描画
        for (x = 200; x < 401; x++)
            data[x][y] = 85;
    }

    for (y = 200; y < 400; y++)
    {
        for (x = 0; x < 200; x++)
            data[x][y] = 255;           // グレイレベル127(灰色)の四角形描画
        for (x = 200; x < 401; x++)
            data[x][y] = 170;
    }

    CglSaveGrayBMP(img, "PaintRect.bmp");
}