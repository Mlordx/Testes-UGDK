#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

// Inheritance
#include <pyramidworks/collision/collisionlogic.h>
#include <stdio.h>

class Bolo : public pyramidworks::collision::CollisionLogic{

  public:
    void Handle(void *bolo){
        Foca* foca = static_cast<Foca*>(bolo);
        foca->Die();
        printf("PUTSPUTSPUTSPUTSPUTS\n");
    }

  private:

};

#endif // COLLISION_H_INCLUDED
