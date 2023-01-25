#include "raylib.h"
#pragma once
class Joint{
    public:
        float tension = -1;
        Limb l2;
        Limb& l1;
        int corner;
        Vector2 size;
        Joint(Limb& _l1, int _corner, Vector2 _size) : l1(_l1){
            corner = _corner;
            size = _size;
            switch (_corner)
            {
            case 0:
                l2 = {_l1.x,_l1.y,_size.x,_size.y,-90,_l1.color};
                break;
            case 1:
                l2 = { _l1.x + _l1.width, _l1.y, _size.x, _size.y, -90, _l1.color};
                break;
            
            default:
                l2 = { _l1.x + _l1.width, _l1.y, _size.x, _size.y, -90, _l1.color};
                break;
            }
        }
        
        void Draw(){

            switch (corner)
            {
            case 0:
                l2.x = l1.x;
                l2.y = l1.y;
                break;
            case 1:
                l2.x = l1.x + l1.width;
                l2.y = l1.y;
                break;

            default:
                l2.x = l1.x + l1.width;
                l2.y = l1.y;
                break;
            }

            l2.rotation = tension * 90;
            DrawLimb(l1);
            DrawLimb(l2);
        }
};
