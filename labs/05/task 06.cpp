/*
Programmer: Syed HUzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
using namespace std;

class GraphicsRenderingEngine {
public:
    void render() {
        cout << "Rendering graphics..." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Handling input..." << endl;
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() {
        cout << "Simulating physics..." << endl;
    }
};

class GameEngine {
private:
    GraphicsRenderingEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void run() {
        cout << "Starting Game Engine..." << endl;
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        graphicsEngine.render();

        cout << "Frame completed." << endl << endl;
        cout << "Game Engine stopped." << endl;
    }
};

int main() {
    GameEngine game;
    game.run();

    return 0;
}