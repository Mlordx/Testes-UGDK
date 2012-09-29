// Inheritance
#include <pyramidworks/collision/collisionlogic.h>
#include <stdio.h>
#include <math.h>

#include "foca.h"
#include "colisaoFocaFoca.h"

void FocaFoca::Handle(void *bolo){
        Foca* foca2 = static_cast<Foca*>(bolo);
        Vector2D posFoca1 = foca_->Position();
        Vector2D posFoca2 = foca2->Position();
        Vector2D velocityFoca1 = foca_->Velocity();
        Vector2D velocityFoca2 = foca2->Velocity();
        double distancia = sqrt(((posFoca1.y - posFoca2.y)*(posFoca1.y - posFoca2.y)) + ((posFoca1.x - posFoca2.x)*(posFoca1.x - posFoca2.x)));
        
        if(distancia<25.0){
            if((posFoca1.y - posFoca2.y)*(posFoca1.y - posFoca2.y)< (posFoca1.x - posFoca2.x)*(posFoca1.x - posFoca2.x))
            {
                velocityFoca1.y*=-1;
                
            }       
            else
            {
                velocityFoca1.x*=-1;
            }  
        }
        foca2->setVelocity(velocityFoca2);
        foca_->setVelocity(velocityFoca1);
        
}

FocaFoca::FocaFoca(Foca* foca1)
{
    foca_ = foca1;

}

