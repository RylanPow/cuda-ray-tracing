#include <iostream>
#include "vec3.h"
#include "ray.h"

bool hit_sphere(const vec3& center, float radius, const ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direciton(), r.direciton());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}
// sphere at C with radius R is: (x - cx)^2 + (y - cy)^2 + (z - cz)^2 = R^2
// in vector form, vector from center to radius of sphere is (p - C)
// len^2 is then ||p - C||^2; sphere in vector form becomes (p-C).(p-C) = R^2
// since ray is p(t) = A + tB, to find intersection, set p = A + tB
// (A + tB - C)^2 = R^2 to find if ray indeed falls on sphere surface
// fully expanded : t^2(B.B) + 2t(B.AC) + (AC.AC) - R^2 = 0
// now quadratic equation; if discriminant b^2 - 4ac is >0, =0, <0...
// >0, 2 real roots(ray enters and exits sphere), =0 1 root, <0 no real roots
// note: v dot v gives magnitude of v^2; remember: u.v = |u||v|cos(theta)



vec3 color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main() {
    int nx = 200;
    int ny = 100;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    for(int j = ny-1; j >= 0; j--) {
        for(int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            std::cout << ir << " " << ig << " " << ib << '\n';
        }
    }
}