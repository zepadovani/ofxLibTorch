#include "ofxLibTorch.h"

namespace ofxLibTorch {
    void teste() {
        if (torch::cuda::is_available()) {
            std::cout << "CUDA is available! Training on GPU." << std::endl;
        } else {
            std::cout << "CUDA is not available! Training on CPU." << std::endl;
        }
    
        // Set device to CUDA if available, otherwise CPU
        torch::Device device(torch::cuda::is_available() ? torch::kCUDA : torch::kCPU);
    
        // Create a tensor on the specified device
        torch::Tensor tensor = torch::rand({2, 3}).to(device);
        std::cout << tensor << std::endl;
    }
}