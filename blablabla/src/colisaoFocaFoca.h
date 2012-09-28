#ifndef COLISAOFOCAFOCA_H_INCLUDED
#define COLISAOFOCAFOCA_H_INCLUDED

// Inheritance
#include <pyramidworks/collision/collisionlogic.h>
#include <stdio.h>

#include "foca.h"

class FocaFoca : public pyramidworks::collision::CollisionLogic{

  public:
    void Handle(void *bolo);
    FocaFoca(Foca* foca1);

  private:
    Foca* foca_;

};

#endif // COLISAOFOCAFOCA_H_INCLUDED
