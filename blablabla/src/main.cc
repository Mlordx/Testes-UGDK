#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <ugdk/action/task.h>
#include <ugdk/action/scene.h>
#include <ugdk/action/entity.h>
#include <ugdk/base/engine.h>
#include <ugdk/math/vector2D.h>
#include <ugdk/input/inputmanager.h>


#include "foca.h"
#include "playerfoca.h"

using ugdk::Vector2D;
using ugdk::action::Scene;


class EscTask : public ugdk::action::Task {
  public:
    EscTask(Scene* scene) : scene_(scene) {}
    
    void operator() (double dt) {
        ugdk::input::InputManager* input = INPUT_MANAGER();
        if(input->KeyPressed(ugdk::input::K_ESCAPE)) {
            scene_->Finish();
        }
    }
  private:
    Scene* scene_;
};

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    
    ugdk::Configuration engine_config;
    engine_config.window_title = "FOCAS - USPGAMEDEV 2012";  
    engine_config.base_path = "/data";
    
    ugdk::Engine* engine = ugdk::Engine::reference();
    engine->Initialize(engine_config);

    Scene* scene = new Scene;
    scene->AddEntity(new PlayerFoca(50.0, 50.0));
    scene->AddEntity(new Foca(250.0, 80.0));
    scene->AddEntity(new Foca(550.0, 120.0));
    scene->AddTask(new EscTask(scene));

    engine->PushScene(scene);
    engine->Run();
    return 0;
}
