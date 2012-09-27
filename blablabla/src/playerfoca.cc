// Header
#include "playerfoca.h"
#include "foca.h"
#include "rastro.h"
#include "collision.h"

// External Deps
#include <ugdk/action/entity.h>
#include <ugdk/action/scene.h>
#include <ugdk/base/engine.h>
//#include <ugdk/base/resourcemanager.h>
#include <ugdk/audio/audiomanager.h>
#include <ugdk/base/types.h>
//#include <ugdk/graphic/drawable.h>
#include <ugdk/graphic/modifier.h>
#include <ugdk/graphic/node.h>
#include <ugdk/graphic/drawable/sprite.h>
//#include <ugdk/graphic/drawable/texturedrectangle.h>
#include <ugdk/input/inputmanager.h>
#include <ugdk/math/vector2D.h>
#include <pyramidworks/collision/collisionobject.h>
#include <pyramidworks/collision/collisionmanager.h>
#include <pyramidworks/geometry/rect.h>

#include <stdio.h>

// Internal Deps


// Using
using ugdk::Color;
using ugdk::Vector2D;
using ugdk::action::Scene;
using ugdk::graphic::Modifier;
using ugdk::graphic::Node;
using ugdk::graphic::Sprite;
//using ugdk::graphic::TexturedRectangle;
using ugdk::input::InputManager;
//using ugdk::base::ResourceManager;
//using ugdk::graphic::Texture;
using pyramidworks::collision::CollisionManager;
using pyramidworks::collision::CollisionObject;

CollisionObject* obj;

PlayerFoca::PlayerFoca(double x, double y, CollisionManager* manager) : velocity_(0.0, 0.0), rotation_(0.0) {
/*
    Texture* textura = ResourceManager::GetTextureFromFile("Foquinha_v0.1.jpg");
    TexturedRectangle* foquinha = new TexturedRectangle(textura,Vector2D(50.0, 50.0));
*/
    Sprite* foca_sprite = new Sprite("foquinha");
    node_ = new Node(foca_sprite);
    node_->modifier()->set_offset(Vector2D(x, y));//muda pos inicial da...foca.

    // CRIAR COLLISION OBJET AQUI
    obj = new CollisionObject(manager, this);
    // torox

    obj->InitializeCollisionClass("focaHero");
    obj->set_shape(new pyramidworks::geometry::Rect(50.0, 50.0));

    ///////////////////////////////////////////////////////////////////
    obj->AddCollisionLogic("gFoca", new Bolo());
    obj->StartColliding();
}

void PlayerFoca::Update(double dt) {

    Modifier* modifier = node_->modifier();
    Vector2D nova_pos = modifier->offset();

    obj->MoveTo(nova_pos);


    velocity_ = Vector2D(0.0); //Velocidade da foca
    rotation_ = modifier->rotation(); //Variavel que altera o vetor velocidade

    InputManager* input = INPUT_MANAGER();
    Scene* scene = ugdk::Engine::reference()->CurrentScene();

    if(input->KeyDown(ugdk::input::K_RIGHT)) {
        rotation_ -= 3.0 * dt;
        modifier->set_rotation(rotation_);
    }
    if(input->KeyDown(ugdk::input::K_LEFT)) {
        rotation_ += 3.0 * dt;
        modifier->set_rotation(rotation_);
    }

    if(input->KeyDown(ugdk::input::K_DOWN)) {
        velocity_=Vector2D(0.0,200.0).Rotate(-rotation_);
    }
    if(input->KeyDown(ugdk::input::K_UP)) {
        velocity_ = Vector2D(0.0,-200.0).Rotate(-rotation_);
    }
    nova_pos += velocity_ * dt;
    //Ifs que impedem as focas de sairem da tela =D
    if(nova_pos.x + node_->drawable()->width()/2.0 > 800 || nova_pos.x < 0.0 + node_->drawable()->width()/2.0) nova_pos -= Vector2D(velocity_.x * dt, 0.0);
    if(nova_pos.y + node_->drawable()->height()/2.0 > 600 || nova_pos.y < 0.0 + node_->drawable()->height()/2.0) nova_pos -= Vector2D(0.0, velocity_.y * dt);

    modifier->set_offset(nova_pos);

    if(input->KeyDown(ugdk::input::K_q)) {
        scene->AddEntity(new Rastro(nova_pos.x,nova_pos.y,-velocity_,rotation_));
    }

    if(input->KeyPressed(ugdk::input::K_q)){
        scene->set_background_music(AUDIO_MANAGER()->LoadMusic("nyancat.mp3"));
        scene->background_music()->PlayForever();
    }

    if(input->KeyReleased(ugdk::input::K_q)){
        scene->set_background_music(AUDIO_MANAGER()->LoadMusic("another_bites.ogg"));
        scene->background_music()->PlayForever();
    }

}

void PlayerFoca::OnSceneAdd(Scene* scene) { //Adiciona a foca à scena no nó "node_"
    scene->content_node()->AddChild(node_);
}
