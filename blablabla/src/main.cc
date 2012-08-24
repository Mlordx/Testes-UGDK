// Header
#include "foca.h"
#include "playerfoca.h"

// External Deps
//#include <cstdio>
//#include <cstdlib>

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
//#include <ugdk/script/languages/lua/luawrapper.h>      // lua not needed
#include <ugdk/script/languages/python/pythonwrapper.h>

// Using
using ugdk::Vector2D;
using ugdk::action::Scene;
using ugdk::AudioManager;

static void InitScripts() {
    //using ugdk::script::python::LuaWrapper;
    using ugdk::script::python::PythonWrapper;
    
    //inicializando lua
    /*
    LuaWrapper* lua_wrapper = new LuaWrapper();
    ugdk::RegisterLuaModules(lua_wrapper);
    pyramidworks::RegisterLuaModules(lua_wrapper);
    SCRIPT_MANAGER()->Register("Lua", lua_wrapper);
    */

    //inicializando python
    PythonWrapper* py_wrapper = new PythonWrapper();
    ugdk::RegisterPythonModules(py_wrapper);
    pyramidworks::RegisterPythonModules(py_wrapper);
    SCRIPT_MANAGER()->Register("Python", py_wrapper);
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

int main(int argc, char *argv[]) {

    ugdk::Configuration engine_config;
    engine_config.window_title = "FOCAS - USPGAMEDEV 2012"; 
    engine_config.base_path = "data/";

    InitScripts();
    ugdk::Engine* engine = ugdk::Engine::reference();
    engine->Initialize(engine_config);
    

    //engine->

    Scene* scene = new Scene;
    scene->AddEntity(new PlayerFoca(250.0, 350.0)); //Mudei a pos. inicial da player foca for the lulz
    scene->AddEntity(new Foca(250.0, 80.0));
    scene->AddEntity(new Foca(550.0, 120.0));
    scene->AddTask(new EscTask(scene));
    scene->set_background_music(AUDIO_MANAGER()->LoadMusic("another_bites.ogg"));

    engine->PushScene(scene);
    engine->Run();
    return 0;
}
