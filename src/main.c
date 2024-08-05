#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#define u32 uint32_t

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 200
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  u32 pixels[SCREEN_WIDTH * SCREEN_HEIGHT];
  bool quit;
} state;

typedef struct v2_t {
  int x;
  int y;
} v2;

#define xyPlane(_x, _y) (_y * SCREEN_WIDTH + _x)
#define abs(_x) ((_x) < 0 ? -(_x) : (_x))
#define max(_x, _y) ((_x) > _y ? (_x) - 1 : (_x))

// Line drawing algorithm - Bresenham's line algorithm
void drawLine(v2 start, v2 end) {
  int dx = abs(end.x - start.x);
  int dy = abs(end.y - start.y);
  int sx = start.x < end.x ? 1 : -1;
  int sy = start.y < end.y ? 1 : -1;
  int err = dx - dy;
  int e2;

  while (true) {
    state.pixels[xyPlane(start.x, start.y)] = 0xFFFFFFFF;
    if (start.x == end.x && start.y == end.y)
      break;
    e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      start.x += sx;
    }
    if (e2 < dx) {
      err += dx;
      start.y += sy;
    }
  }
}

void render() {
  drawLine((v2){0, 0}, (v2){SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20});
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  state.window =
      SDL_CreateWindow("DEMO", SDL_WINDOWPOS_CENTERED_DISPLAY(0),
                       SDL_WINDOWPOS_CENTERED_DISPLAY(0), WINDOW_WIDTH,
                       WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
  state.renderer =
      SDL_CreateRenderer(state.window, -1, SDL_RENDERER_PRESENTVSYNC);

  state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ARGB8888,
                                    SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH,
                                    SCREEN_HEIGHT);

  while (!state.quit) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      switch (ev.type) {
      case SDL_QUIT:
        state.quit = true;
      }
    }
    memset(state.pixels, 0, sizeof(state.pixels));
    render();

    SDL_UpdateTexture(state.texture, NULL, state.pixels, SCREEN_WIDTH * 4);
    SDL_RenderCopyEx(state.renderer, state.texture, NULL, NULL, 0.0, NULL,
                     SDL_FLIP_VERTICAL);
    SDL_RenderPresent(state.renderer);
  }
  SDL_DestroyTexture(state.texture);
  SDL_DestroyRenderer(state.renderer);
  SDL_DestroyWindow(state.window);
  SDL_Quit();
  return 0;
}
