#ifndef PLAYERFOCA_H
#define PLAYERFOCA_H


// Inheritance
#include <ugdk/action/entity.h>

// External Derps
#include <ugdk/math/vector2D.h>

// Internal Derps

// Forward Declarations
#include <ugdk/action.h>
#include <ugdk/graphic.h>
#include <pyramidworks/collision.h>


class PlayerFoca : public ugdk::action::Entity {
  public:
    PlayerFoca(double x, double y, pyramidworks::collision::CollisionManager* manager);
    void Update(double dt);
    void OnSceneAdd(ugdk::action::Scene* scene);

  private:
    ugdk::Vector2D velocity_;
    double rotation_;
    ugdk::graphic::Node* node_;
};

#endif // PLAYERFOCA_H
