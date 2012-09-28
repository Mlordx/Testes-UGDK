
// Header
#include "foca.h"
#include "collision.h"
#include "colisaoFocaFoca.h"

// External Deps
#include <ugdk/action/entity.h>
#include <ugdk/action/scene.h>
#include <ugdk/base/engine.h>
#include <ugdk/base/types.h>
#include <ugdk/graphic/drawable.h>
#include <ugdk/graphic/modifier.h>
#include <ugdk/graphic/node.h>
#include <ugdk/graphic/drawable/solidrectangle.h>
#include <ugdk/math/vector2D.h>
#include <ugdk/input/inputmanager.h>

#include <iostream>


// Internal Deps

// Using
using ugdk::Color;
using ugdk::Vector2D;
using ugdk::action::Scene;
using ugdk::graphic::Modifier;
using ugdk::graphic::Node;
using ugdk::graphic::SolidRectangle;
using ugdk::input::InputManager;
using pyramidworks::collision::CollisionManager;
using pyramidworks::collision::CollisionObject;
using pyramidworks::collision::CollisionLogic;



double randDouble() {
    return rand() / static_cast<double>(RAND_MAX);
}

Foca::Foca(double x, double y,CollisionManager* manager) : velocity_(200, 0.0), delayRotation_(0) {
    SolidRectangle* solid = new SolidRectangle(Vector2D(25.0, 25.0));
    solid->set_color(Color(randDouble(), randDouble(), randDouble(), 0.5));
    node_ = new Node(solid);
    node_->modifier()->set_offset(Vector2D(x, y));
    node_->drawable()->set_hotspot(ugdk::graphic::Drawable::CENTER);
    
    object_ = new CollisionObject(manager,this);

    object_->InitializeCollisionClass("gFoca");
    object_->set_shape(new pyramidworks::geometry::Rect(25.0, 25.0));
    CollisionLogic* logic = new FocaFoca(this);
    object_->AddCollisionLogic("gFoca",logic );
    object_->StartColliding();
    object_->MoveTo(Vector2D(x,y));
}

Foca::~Foca(){
delete node_;
delete object_;
}

void Foca::Update(double dt) {
    Modifier* modifier = node_->modifier();
    Vector2D nova_pos = modifier->offset();
    double pode_andar = 0.0;
    double random= randDouble();
    delayRotation_+= dt;
    if(delayRotation_>1){
      velocity_=velocity_.Rotate(random);
      delayRotation_ = 0;
     }
    nova_pos += velocity_ * dt;

    if(nova_pos.x + node_->drawable()->width()/2.0 > 800) {
        pode_andar = modifier->offset().x + node_->drawable()->width()/2.0 - 800;

        nova_pos.x += pode_andar - (velocity_.x * dt - pode_andar);
        velocity_.x *= -1;
        
    } else if (nova_pos.x < 0.0 + node_->drawable()->width()/2.0) {
        pode_andar = modifier->offset().x - node_->drawable()->width()/2.0;

        nova_pos.x += pode_andar - (velocity_.x * dt - pode_andar);

        velocity_.x *= -1;
    }

    if(nova_pos.y + node_->drawable()->height()/2.0 > 600) {
        pode_andar = modifier->offset().y + node_->drawable()->height()/2.0 - 600;

        nova_pos.y += pode_andar - (velocity_.y * dt - pode_andar);

        velocity_.y *= -1;
    } else if (nova_pos.y < 0.0 + node_->drawable()->height()/2.0) {
        pode_andar = modifier->offset().y - node_->drawable()->height()/2.0;

        nova_pos.y += pode_andar - (velocity_.y * dt - pode_andar);

        velocity_.y *= -1;
    }


    modifier->set_offset(nova_pos);
    object_->MoveTo(nova_pos);
}

void Foca::OnSceneAdd(Scene* scene) {
    scene->content_node()->AddChild(node_);
}

Vector2D Foca::Position(){
    return node_->modifier()->offset();
}

Vector2D Foca::Velocity()
{
    return velocity_;
}

void Foca::setVelocity(Vector2D novaVelocity)
{
    velocity_ = novaVelocity;
}

