#include <ugdk/base/engine.h>
#include <ugdk/action/scene.h>

#include <ugdk/action/task.h>
#include <ugdk/action/entity.h>
#include <ugdk/math/vector2D.h>
#include <ugdk/input/inputmanager.h>

#include "player.h"
#include "player.cc"

int main(int argc,char **argv) {
    ugdk::Engine* engine = ugdk::Engine::reference();
    engine->Initialize();

    ugdk::action::Scene* scene = new ugdk::action::Scene;

    scene->AddEntity(new Player(100.0, 100.0));

    engine->PushScene(scene);
    engine->Run();
    engine->Release();

    return 0;
}
