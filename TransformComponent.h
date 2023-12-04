#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component{

    public:
        Vector2D position;

        TransformComponent(){
            position.x = 0.0f;
            posotion.y = 0.0f;
        }

        TransformComponent(int x, int y){
            xpos = x;
            ypos = y;
        }
        int x() { return xpos; }
        int y() { return ypos; }
        void x(int x) { xpos = x; }
        void y(int y) { ypos = y; }
/*
        void init() override{
            xpos = 0;
            ypos = 0;
        }*/

        void update() override {
            xpos++;
            ypos++;
        }
        void setPos(int x, int y) {
            xpos = x;
            ypos = y;
        }
};
