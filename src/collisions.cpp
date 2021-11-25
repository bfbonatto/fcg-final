#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>



bool boid_boid(glm::vec3 c1, float r1, glm::vec3 c2, float r2) {
    return (c1 - c2).length() <= (r1+r2);
}
bool boid_ground(glm::vec3 c, float r, float height) {
    return r+height >= c.x;
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
