
// Header
#include "rastro.h"

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


double randDouble2() {
    return rand() / static_cast<double>(RAND_MAX);
}

Rastro::Rastro(double x, double y,ugdk::Vector2D velocidade, double rotation) : velocity_(velocidade), maxLife_(2.5), life_ (maxLife_) {
    SolidRectangle* solid = new SolidRectangle(Vector2D(50.0, 50.0));
    solid->set_color(Color(randDouble2(), randDouble2(), randDouble2(), 1));
    node_ = new Node(solid);
    node_->modifier()->set_offset(Vector2D(x, y));
    node_->drawable()->set_hotspot(ugdk::graphic::Drawable::CENTER);
    node_->modifier()->set_rotation(rotation);
    if (velocity_.NormOne() == 0) {
        velocity_=Vector2D(0.0,200.0).Rotate(-rotation);
    }
}

Rastro::~Rastro(){
    delete node_;
} 

void Rastro::Update(double dt) {
    Modifier* modifier = node_->modifier();
    Vector2D nova_pos = modifier->offset();
    double pode_andar = 0.0;
    
    nova_pos += velocity_ * dt;

    life_ -= dt;
    
    if(life_ <= 0 /*MORTEEEEEEEEEEEEE*/) to_be_removed_ = true; 
    
    cor_ =  node_->modifier()->color();
    cor_.set_a(0.5 - (maxLife_ -life_)/(2 * maxLife_));
    node_->modifier()->set_color(cor_);
    
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
}

void Rastro::OnSceneAdd(Scene* scene) {
    scene->content_node()->AddChild(node_);
}

