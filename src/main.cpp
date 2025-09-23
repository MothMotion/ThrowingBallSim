#include "program.h"
#include "vec2.h"
#include "display.h"

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>

#include <raylib.h>

// Scale falloff value for smooth camera/
constexpr double SFALLOFF = 0.99;

int main (int argc, char *argv[]) {
  if(argc != 13) {// x, y, radius, vx, vy, left_x, right_x, elevation, delta, eps, grav_x, grav_y
    std::cout << "Invalid number of arguments!\nx y radius vx vy left_x right_x elevation delta eps grav_x grav_y";
    return -1;
  }

  const double radius = atof(argv[3]),
               left_x = atof(argv[6]),
               right_x = atof(argv[7]),
               elevation = atof(argv[8]),
               delta = atof(argv[9]),
               eps = atof(argv[10]);
  const vec2 grav(atof(argv[11]), atof(argv[12]));

  Step* steps[2]{new Step(atof(argv[1]), atof(argv[2]), atof(argv[4]), atof(argv[5])), new Step()};

  const int screenWidth = 800,
            screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "MatAn Simulaiton");

  SetTargetFPS(60);

  vec2 max_view(radius, radius);
  double view_scale = 0;

  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  while(!registerHit(*steps[0], radius, eps, left_x, right_x, elevation) &&
        steps[0]->pos.y >= -eps) {
    nextStep(delta, grav, *steps[0], *steps[1]);
    std::swap(steps[0], steps[1]);
    std::cout << "\nCycle\n";

    BeginDrawing();
      ClearBackground(RAYWHITE);
      max_view.x = std::max(max_view.x * SFALLOFF, std::max(steps[0]->pos.x + radius/2, right_x + radius/2));
      max_view.y = std::max(max_view.y * SFALLOFF, std::max(steps[0]->pos.y + radius/2, elevation));
      view_scale = std::min(screenWidth / max_view.x, screenHeight / max_view.y);
      DrawText(TextFormat("Scale:%.2f;\nPos(%.2f;%.2f);\n", view_scale, steps[0]->pos.x, steps[0]->pos.y), 10, 10, 16, BLACK);
 
      drawStep(screenWidth, screenHeight, steps[0]->pos.x * view_scale, steps[0]->pos.y * view_scale, radius * view_scale,
               left_x * view_scale, right_x * view_scale, elevation, 1 * view_scale, 12 * view_scale, GREEN, RED, BLUE);
    EndDrawing();
  }

  std::cout << "\n\n??? > " << steps[0]->pos.y << "\n";
  if(steps[0]->pos.y < -eps) {
    if(left_x + eps <= steps[0]->pos.x && steps[0]->pos.x <= right_x - eps)
      std::cout << "DUNK!\n";
    else
      std::cout << "no dunk :(\n";
  } else
    std::cout << "Hit ring\n";
  std::cout << "Throw accuracy: " << std::abs((right_x + left_x)/2 - steps[0]->pos.x);
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));

  CloseWindow();

  return 0;
}
