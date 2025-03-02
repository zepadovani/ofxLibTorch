#include "ofMain.h"
#include "ofApp.h"

int main() {
    std::cout << "main starting..." << std::endl;
    ofSetupOpenGL(2048, 1024, OF_WINDOW);
    ofRunApp(new ofApp());
}