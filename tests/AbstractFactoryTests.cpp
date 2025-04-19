#include "gtest/gtest.h"
#include <sstream>
#include <memory>

// Reuse the interfaces and classes from main.cpp
// In real projects, put class definitions in headers

class TestWindow : public Window {
public:
    std::ostringstream& out;
    TestWindow(std::ostringstream& o) : out(o) {}
    void render() override {
        out << "Test Window Rendered\n";
    }
};

class TestScrollbar : public Scrollbar {
public:
    std::ostringstream& out;
    TestScrollbar(std::ostringstream& o) : out(o) {}
    void render() override {
        out << "Test Scrollbar Rendered\n";
    }
};

class TestGUIFactory : public GUIFactory {
    std::ostringstream& out;
public:
    TestGUIFactory(std::ostringstream& o) : out(o) {}

    std::unique_ptr<Window> createWindow() override {
        return std::make_unique<TestWindow>(out);
    }

    std::unique_ptr<Scrollbar> createScrollbar() override {
        return std::make_unique<TestScrollbar>(out);
    }
};

TEST(AbstractFactoryTest, RenderComponents) {
    std::ostringstream output;
    TestGUIFactory factory(output);
    
    auto window = factory.createWindow();
    auto scrollbar = factory.createScrollbar();

    window->render();
    scrollbar->render();

    EXPECT_EQ(output.str(), "Test Window Rendered\nTest Scrollbar Rendered\n");
}
