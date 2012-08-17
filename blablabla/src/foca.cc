
// Header
#include "foca.h"

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

// Internal Deps

// Using
using ugdk::Color;
using ugdk::Vector2D;
using ugdk::action::Scene;
using ugdk::graphic::Modifier;
using ugdk::graphic::Node;
using ugdk::graphic::SolidRectangle;
using ugdk::input::InputManager;


double randDouble() {
    return rand() / static_cast<double>(RAND_MAX);
}

Foca::Foca(double x, double y) : velocity_(200, 0.0) {
    SolidRectangle* solid = new SolidRectangle(Vector2D(50.0, 50.0));
    solid->set_color(Color(randDouble(), randDouble(), randDouble(), 0.5));
    node_ = new Node(solid);
    node_->modifier()->set_offset(Vector2D(x, y));
    node_->drawable()->set_hotspot(ugdk::graphic::Drawable::CENTER);
}

void Foca::Update(double dt) {
    Modifier* modifier = node_->modifier();
    Vector2D nova_pos = modifier->offset();
    
    nova_pos += velocity_ * dt;
    
    if(nova_pos.x + node_->drawable()->width()/2.0 > 800 || nova_pos.x < 0.0 + node_->drawable()->width()/2.0) velocity_.x *= -1;

    modifier->set_offset(nova_pos);
}

void Foca::OnSceneAdd(Scene* scene) {
    scene->content_node()->AddChild(node_);
}

