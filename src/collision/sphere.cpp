#include <nanogui/nanogui.h>

#include "../clothMesh.h"
#include "../misc/sphere_drawing.h"
#include "sphere.h"

using namespace nanogui;
using namespace CGL;

void Sphere::collide(PointMass &pm) {
  // TODO (Part 3): Handle collisions with spheres.
    Vector3D v = pm.position - origin;
    if (v.norm() < radius) {
        v.normalize();
        v *= radius;
        v += origin;
        // v is now tangent point

        v -= pm.last_position;
        v *= (1.0 - friction);
        pm.position = pm.last_position + v;
    }
}

void Sphere::render(GLShader &shader) {
  // We decrease the radius here so flat triangles don't behave strangely
  // and intersect with the sphere when rendered
  m_sphere_mesh.draw_sphere(shader, origin, radius * 0.92);
}
