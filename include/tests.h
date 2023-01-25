#include "joint.h"
#include <math.h>
void Distance_joint_point(Joint j1, Vector2 point){
    
    Vector2 v3; // reffering to the 3rd corner of the second limb of a joint
    float hyp = sqrt((pow(j1.l2.width, 2) + pow(j1.l2.height, 2)));
    float rot = (j1.l2.rotation * (PI / 180));
    v3.x = j1.l2.x + hyp * cos(rot + atan(float(j1.l2.height) / float(j1.l2.width)));
    v3.y = j1.l2.y - hyp * sin(rot + atan(float(j1.l2.height) / float(j1.l2.width)));

    printf("Distance to point from joint: %f \n",Distance(v3,point));
};