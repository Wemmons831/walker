#include "raylib.h"
#include <vector>
#include <math.h>
struct Limb
{
    int x;
    int y;
    int width;
    int height;
    float rotation;
    Color color;
};

float Distance(Vector2 v1, Vector2 v2){
    return sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));
}

void DrawLimb(Limb limb){
    Vector2 v1 = {limb.x,limb.y};
    Vector2 v4 = {limb.x + limb.width,limb.y};
    Vector2 v2 = {limb.x, limb.y - limb.height};
    Vector2 v3 = {limb.x + limb.width, limb.y - limb.height};
    
    float hyp = sqrt((pow(limb.width, 2) + pow(limb.height, 2)));
    float rot = (limb.rotation * (PI / 180));

    v3.x = v1.x + hyp * cos(rot + atan(float(limb.height) / float(limb.width)));
    v3.y = v1.y - hyp * sin(rot + atan(float(limb.height) / float(limb.width)));

    v4.x = v1.x + limb.width * cos(rot);
    v4.y = v1.y - limb.width * sin(rot);

    v2.x = v1.x - limb.height * sin(rot);
    v2.y = v1.y - limb.height * cos(rot);

    
    DrawTriangle(v1, v3, v2,limb.color);
    DrawTriangle(v4, v3, v1, limb.color);
    
}

