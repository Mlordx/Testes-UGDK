#ifndef RASTRO_H
#define RASTRO_H

// Inheritance
#include <ugdk/action/entity.h>

// External Deps
#include <ugdk/math/vector2D.h>
#include <ugdk/graphic/drawable.h>
#include <ugdk/graphic/modifier.h>

// Internal Deps

// Forward Declarations
#include <ugdk/action.h>
#include <ugdk/graphic.h>

using ugdk::Color;

class Rastro : public ugdk::action::Entity {
  public:
    Rastro(double x, double y, ugdk::Vector2D velocidade);
    ~Rastro();
    void Update(double dt);
    void OnSceneAdd(ugdk::action::Scene* scene);

  private:
    ugdk::Vector2D velocity_;
    ugdk::graphic::Node* node_;
    double maxLife_;
    double life_;
    Color cor_;
};

#endif // RASTRO_H
