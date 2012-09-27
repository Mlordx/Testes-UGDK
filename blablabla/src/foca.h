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
#include <pyramidworks/geometry/rect.h>
#include <pyramidworks/collision/collisionobject.h>

// Using
using pyramidworks::collision::CollisionManager;
using pyramidworks::collision::CollisionObject;

class Foca : public ugdk::action::Entity {
  public:
    Foca(double x, double y,CollisionManager* manager);
    ~Foca();
    void Update(double dt);
    void OnSceneAdd(ugdk::action::Scene* scene);
    void Die() { to_be_removed_ = true; };

  private:
    ugdk::Vector2D velocity_;
    ugdk::graphic::Node* node_;
    CollisionObject* object_;
    double delayRotation_;
};

#endif // FOCA_H
