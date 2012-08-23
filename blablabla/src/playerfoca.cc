// Header
#include "playerfoca.h"

// External Deps
#include <ugdk/action/entity.h>
#include <ugdk/action/scene.h>
#include <ugdk/base/engine.h>
#include <ugdk/base/types.h>
#include <ugdk/graphic/drawable.h>
#include <ugdk/graphic/modifier.h>
#include <ugdk/graphic/node.h>
#include <ugdk/graphic/drawable/texturedrectangle.h>
#include <ugdk/input/inputmanager.h>
#include <ugdk/math/vector2D.h>


// Internal Deps


// Using
using ugdk::Color;
using ugdk::Vector2D;
using ugdk::action::Scene;
using ugdk::graphic::Modifier;
using ugdk::graphic::Node;
using ugdk::graphic::TexturedRectangle;
using ugdk::input::InputManager;

PlayerFoca::PlayerFoca(double x, double y) : velocity_(0.0, 0.0), rotation_(0.0) {
    TexturedRectangle* foquinha = new TexturedRectangle(Vector2D(50.0, 50.0)); //EDITAR ESSA LINHA
    node_ = new Node(foquinha);
    node_->modifier()->set_offset(Vector2D(x, y));//muda pos inicial da...foca.
    node_->drawable()->set_hotspot(ugdk::graphic::Drawable::CENTER);
}

void PlayerFoca::Update(double dt) {

    Modifier* modifier = node_->modifier();
    Vector2D nova_pos = modifier->offset();

    velocity_ = Vector2D(0.0); //Velocidade da foca
    rotation_ = modifier->rotation(); //Variavel que altera o vetor velocidade

    InputManager* input = INPUT_MANAGER();

    if(input->KeyDown(ugdk::input::K_RIGHT)) {
        rotation_ -= 3.0 * dt;
        modifier->set_rotation(rotation_);
    }
    if(input->KeyDown(ugdk::input::K_LEFT)) {
        rotation_ += 3.0 * dt;
        modifier->set_rotation(rotation_);
    }

    if(input->KeyDown(ugdk::input::K_DOWN)) {
        //velocity_=Vector2D(0.0,200.0);
        velocity_=Vector2D(0.0,200.0)->Rotate(-rotation_);
    }
    if(input->KeyDown(ugdk::input::K_UP)) {
        //velocity_=Vector2D(0.0,-200.0);
        velocity_ = Vector2D(0.0,-200.0)->Rotate(-rotation_);
    }

    nova_pos += velocity_ * dt;

    //Ifs que impedem as focas de sairem da tela =D
    if(nova_pos.x + node_->drawable()->width()/2.0 > 800 || nova_pos.x < 0.0 + node_->drawable()->width()/2.0) nova_pos -= Vector2D(velocity_.x * dt, 0.0);
    if(nova_pos.y + node_->drawable()->height()/2.0 > 600 || nova_pos.y < 0.0 + node_->drawable()->height()/2.0) nova_pos -= Vector2D(0.0, velocity_.y * dt);

    modifier->set_offset(nova_pos);
}

void PlayerFoca::OnSceneAdd(Scene* scene) { //Adiciona a foca à scena no nó "node_"
    scene->content_node()->AddChild(node_);
}
