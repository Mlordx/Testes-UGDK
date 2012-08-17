#ifndef PLAYERFOCA_H
#define PLAYERFOCA_H

#include <ugdk/action/entity.h>
#include <ugdk/math/vector2D.h>
#include <ugdk/action.h>
#include <ugdk/graphic.h>



class Player : public ugdk::action::Entity {

  typedef ugdk::action::Entity super;

  public:
    Player(int x,int y);
    void Update(double dt);
    void OnSceneAdd(ugdk::action::Scene* scene);
  private:
    ugdk::Vector2D velocity_;
    double rotation_;
    ugdk::graphic::Node* node_;
    
};

#endif // PLAYERFOCA_H
