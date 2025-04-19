#include <iostream>
#include <memory>

// Interface for Window
class Window {
public:
    virtual void render() = 0;
    virtual ~Window() = default;
};

// Interface for Scrollbar
class Scrollbar {
public:
    virtual void render() = 0;
    virtual ~Scrollbar() = default;
};

// Concrete WindowsWindow
class WindowsWindow : public Window {
public:
    void render() override {
        std::cout << "Rendering Windows Window\n";
    }
};

// Concrete WindowsScrollbar
class WindowsScrollbar : public Scrollbar {
public:
    void render() override {
        std::cout << "Rendering Windows Scroll bar. Give me the header file.\n";
    }
};

// Concrete LinuxWindow
class LinuxWindow : public Window {
public:
    void render() override {
        std::cout << "Rendering Linux Window\n";
    }
};

// Concrete LinuxScrollbar
class LinuxScrollbar : public Scrollbar {
public:
    void render() override {
        std::cout << "Rendering Linux Scrollbar\n";
    }
};

// Abstract Factory
class GUIFactory {
public:
    virtual std::unique_ptr<Window> createWindow() = 0;
    virtual std::unique_ptr<Scrollbar> createScrollbar() = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Windows Factory
class WindowsGUIFactory : public GUIFactory {
public:
    std::unique_ptr<Window> createWindow() override {
        return std::make_unique<WindowsWindow>();
    }
    std::unique_ptr<Scrollbar> createScrollbar() override {
        return std::make_unique<WindowsScrollbar>();
    }
};

// Concrete Linux Factory
class LinuxGUIFactory : public GUIFactory {
public:
    std::unique_ptr<Window> createWindow() override {
        return std::make_unique<LinuxWindow>();
    }
    std::unique_ptr<Scrollbar> createScrollbar() override {
        return std::make_unique<LinuxScrollbar>();
    }
};

// Client code
void buildGUI(std::unique_ptr<GUIFactory> factory) {
    auto window = factory->createWindow();
    auto scrollbar = factory->createScrollbar();

    window->render();
    scrollbar->render();
}

int main() {
    std::cout << "Using Windows GUI Factory:\n";
    buildGUI(std::make_unique<WindowsGUIFactory>());

    std::cout << "\nUsing Linux GUI Factory:\n";
    buildGUI(std::make_unique<LinuxGUIFactory>());

    return 0;
}
