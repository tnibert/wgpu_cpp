#include <webgpu/webgpu.h>
#include <iostream>

int main (int, char**) {
    std::cout << "Hello, world!" << std::endl;

    // We create a descriptor
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

#ifdef WEBGPU_BACKEND_EMSCRIPTEN
    // emscripten requires nullptr descriptor
    WGPUInstance instance = wgpuCreateInstance(nullptr);
#else
    // Create the instance using the descriptor
    WGPUInstance instance = wgpuCreateInstance(&desc);
#endif

    // We can check whether there is actually an instance created
    if (!instance) {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }

    // Display the object (WGPUInstance is a simple pointer, it may be
    // copied around without worrying about its size).
    std::cout << "WGPU instance: " << instance << std::endl;

    // Clean up the WebGPU instance
    wgpuInstanceRelease(instance);

    return 0;
}
