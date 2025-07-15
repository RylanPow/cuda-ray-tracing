# CUDA-Accelerated Ray Tracer
Adapted from the famous Ray Tracing in One Weeekend by Peter Shirley.  This GPU project is an exercise in accelerating embarassingly parallel computation flows with a GPU.

Below is an example generated output by this ray tracer:
![image](https://github.com/user-attachments/assets/c1c1de0c-09dd-4c09-89fe-f82a57cd49ce)
The above scene consists of 100 randomly generated spheres of various optical materials and 4 specifically generated spheres.  The scene is a 1200x800 image with 10 samples for anti-aliasing.

I originally constructed the ray tracer according to the book, which is a CPU ray tracer.  I later worked on translating the files from sequential C++ to parallelized CUDA.  The C++ ray tracer took 178 seconds to execute when I ran it, while the parallelized CUDA code only took 16.4 seconds.  That is a decrease of **over 90%**, or in increase in exeecution speed of **1,000%**.

The engine features: positionable camera, multi-sample anti-aliasing, and 3 materials of differing optical properties(Lambertian(matte), metallic, and dielectric(e.g. glass)).  To run the engine and generate a scene, open and execute _kernel.cu_ in Visual Studio with CUDA installed.  It should output a .ppm image called _output.ppm_ to x64/debug.  You may need a special application to read .ppm files; I just used an online .ppm viewer.

