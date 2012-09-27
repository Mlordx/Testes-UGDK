#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

// Inheritance
#include <pyramidworks/collision/collisionlogic.h>
#include <stdio.h>

class Bolo : public pyramidworks::collision::CollisionLogic{

  public:
    void Handle(void *bolo){
        printf("PUTSPUTSPUTSPUTSPUTS\n");
    }

  private:

};

#endif // COLLISION_H_INCLUDED
