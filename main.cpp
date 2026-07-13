#include "renderer.h"
#include "scene_graph.h"
#include <chrono>
#include <thread>

int main() {
  SceneGraph scene;

  Renderer renderer;

  scene.setup();
  renderer.setup();

  while (true) {
    renderer.handleEvents();

    scene.update();

    renderer.render();

    std::this_thread::sleep_for(std::chrono::milliseconds(16));
  }
  return 0;
}
