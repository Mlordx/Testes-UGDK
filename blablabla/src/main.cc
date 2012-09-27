// Header
#include "foca.h"
#include "rastro.h"
#include "playerfoca.h"

// External Deps
//#include <cstdio>
//#include <cstdlib>

#include <pyramidworks/collision/collisionmanager.h>
#include <ugdk/action/task.h>
#include <ugdk/action/scene.h>
#include <ugdk/action/entity.h>
#include <ugdk/audio/audiomanager.h>
#include <ugdk/audio/music.h>
#include <ugdk/base/engine.h>
#include <ugdk/math/vector2D.h>
#include <ugdk/input/inputmanager.h>

// Required for initializing scripts
#include <ugdk/modules.h>
#include <pyramidworks/modules.h>
#include <ugdk/script/scriptmanager.h>
#include <ugdk/script/languages/lua/luawrapper.h>
//#include <ugdk/script/languages/python/pythonwrapper.h> // python not needed

// Using
using ugdk::Vector2D;
using ugdk::action::Scene;
using ugdk::AudioManager;
using pyramidworks::collision::CollisionManager;

// globals omg
CollisionManager* collision_manager;

static void InitScripts() {
    using ugdk::script::lua::LuaWrapper;
    //using ugdk::script::python::PythonWrapper;

    //inicializando lua
    LuaWrapper* lua_wrapper = new LuaWrapper();
    ugdk::RegisterLuaModules(lua_wrapper);
    pyramidworks::RegisterLuaModules(lua_wrapper);
    SCRIPT_MANAGER()->Register("Lua", lua_wrapper);

    /*
    //inicializando python
    PythonWrapper* py_wrapper = new PythonWrapper();
    ugdk::RegisterPythonModules(py_wrapper);
    pyramidworks::RegisterPythonModules(py_wrapper);
    SCRIPT_MANAGER()->Register("Python", py_wrapper);
    */
}

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

void createCollisionStuff(){

  ugdk::Vector2D top_left;
  ugdk::Vector2D bottom_right(800.0,600.0);
  ugdk::ikdtree::Box<2> box(top_left.val, bottom_right.val);
  collision_manager = new CollisionManager(box);

  collision_manager->Generate("focaHero");
  collision_manager->Generate("gFoca");
  collision_manager->Generate("wall");
}

int main(int argc, char *argv[]) {

    ugdk::Configuration engine_config;
    engine_config.window_title = "FOCAS - USPGAMEDEV 2012";
    engine_config.base_path = "data/";

    InitScripts();
    ugdk::Engine* engine = ugdk::Engine::reference();
    engine->Initialize(engine_config);


    //engine->
    createCollisionStuff();
    Scene* scene = new Scene;
    scene->AddEntity(new PlayerFoca(250.0, 350.0, collision_manager)); //Mudei a pos. inicial da player foca for the lulz
    scene->AddEntity(new Foca(250.0, 80.0,collision_manager));
    scene->AddEntity(new Foca(550.0, 120.0,collision_manager));
    scene->AddTask(new EscTask(scene));
    scene->set_background_music(AUDIO_MANAGER()->LoadMusic("another_bites.ogg"));
    scene->AddTask(collision_manager->GenerateHandleCollisionTask());

    engine->PushScene(scene);
    engine->Run();
    return 0;
}
