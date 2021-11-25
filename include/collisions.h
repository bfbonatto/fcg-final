#ifndef _COLLISIONS_H
#define _COLLISIONS_H

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>


bool boid_boid(glm::vec3 c1, float r1, glm::vec3 c2, float r2) {
    //printf("c1=(%f,%f,%f) r1=%f c2=(%f,%f,%f) r2=%f\n", c1.x, c1.y, c1.z,r1, c2.x, c2.y, c2.z,r2);
    //printf("dist=%f r1+r2=%f\n", (c1-c2).length(), r1+r2);
    return distance(c1,c2) <= (r1+r2);
}
bool boid_ground(glm::vec3 c, float r, float height) {
    return r+height >= c.y;
}
inline float sqr(float v) { return v*v; }
bool boid_cow(glm::vec3 c1, glm::vec3 c2, glm::vec3 s, float r) {
    float r2 = r*r;
    if (s.x < c1.x) r2 -= sqr(s.x - c1.x);
    else if (s.x > c2.x) r2 -= sqr(s.x - c2.x);
    if (s.y < c1.y) r2 -= sqr(s.y - c1.y);
    else if (s.y > c2.y) r2 -= sqr(s.y - c2.y);
    if (s.z < c2.z) r2 -= sqr(s.z - c2.z);
    else if (s.z > c2.z) r2 -= sqr(s.z - c2.z);
    return r2 > 0;

}



#endif
