#ifndef FOCA_H
#define FOCA_H

// Inheritance
#include <ugdk/action/entity.h>

// External Deps
#include <ugdk/math/vector2D.h>

// Internal Deps

// Forward Declarations
#include <ugdk/action.h>
#include <ugdk/graphic.h>


class Foca : public ugdk::action::Entity {
  public:
    Foca(double x, double y);
    void Update(double dt);
    void OnSceneAdd(ugdk::action::Scene* scene);

  private:
    ugdk::Vector2D velocity_;
    ugdk::graphic::Node* node_;
};

#endif // FOCA_H
