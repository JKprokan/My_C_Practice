#include    <stdio.h>
// 幅xsizeピクセル 高さysizeピクセルの画像データimage[][]を文字で描く関数
void DrawCharImage(unsigned char* image, int xsize, int ysize);
#define WIDTH   15      // 画像の幅(ピクセル数)
#define HEIGHT  10      // 画像の高さ(ピクセル数)
int main(void)
{
unsigned char image[WIDTH][HEIGHT]; // 画像データ配列の宣言
int i, j;                           // ループ変数
for (i = 0; i < WIDTH; i++)         // 2重ループで画像を一旦ゼロにクリアする
{
for (j = 0; j < HEIGHT; j++)
image[i][j] = 0;
}
for (i = 0; i < WIDTH; i++)         // 横線を引く
{
image[i][HEIGHT/2] = 1;         // 横線はちょうど真ん中で引く
}
for (j = 0; j < HEIGHT; j++)        // 縦線を引く
{
image[WIDTH/2][j] = 1;          // 縦線もちょうど真ん中で引く
}
DrawCharImage((unsigned char*) image, WIDTH, HEIGHT); //画像描画関数呼び出し
}