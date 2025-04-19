# Abstract Factory Design Pattern Example

## Problem Statement

In software development, we often need to ensure that a family of related or dependent objects work together and are created consistently. The Abstract Factory pattern provides a way to encapsulate a group of individual factories that have a common theme without specifying their concrete classes.

This pattern is particularly useful when:

1. A system should be independent of how its products are created, composed, and represented
2. A system should be configured with one of multiple families of products
3. A family of related product objects is designed to be used together
4. You want to provide a class library of products, and you want to reveal just their interfaces, not their implementations

## Project Overview

This project implements a furniture manufacturing system using the Abstract Factory pattern with the following components:

1. Abstract product interfaces (`Chair`, `Table`, `Sofa`)
2. Concrete product implementations for different styles (Modern, Victorian, Art Deco)
3. An abstract factory interface (`FurnitureFactory`)
4. Concrete factory implementations for each style

## The Abstract Factory Design Pattern

### What is the Abstract Factory Pattern?

The Abstract Factory is a creational design pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes. It's a higher-level version of the Factory Method pattern, creating entire families of related objects.

### Structure of the Abstract Factory Pattern

1. **Abstract Products**: Interfaces for a family of distinct but related products (`Chair`, `Table`, `Sofa`)
2. **Concrete Products**: Different implementations of the product interfaces (`ModernChair`, `VictorianTable`, etc.)
3. **Abstract Factory**: The interface declaring creation methods for each abstract product (`FurnitureFactory`)
4. **Concrete Factories**: Classes implementing the creation methods to produce a specific family of products (`ModernFurnitureFactory`, etc.)
5. **Client**: Code that works with factories and products only through their abstract types

### Problem Addressed by the Abstract Factory Pattern

The Abstract Factory pattern solves the problem of:
- Creating families of related objects without hardcoding their concrete classes
- Ensuring that created objects work together correctly
- Enforcing constraints on which object combinations can be created
- Providing a way to exchange entire families of products easily

## Implementation Details

### The Abstract Products

These interfaces define what each type of product must be able to do:

```cpp
// Chair interface
class Chair {
public:
    virtual ~Chair() = default;
    virtual std::string sitOn() const = 0;
    virtual std::string getStyle() const = 0;
};

// Table interface
class Table {
public:
    virtual ~Table() = default;
    virtual std::string putOn() const = 0;
    virtual std::string getStyle() const = 0;
};

// Sofa interface
class Sofa {
public:
    virtual ~Sofa() = default;
    virtual std::string lieOn() const = 0;
    virtual std::string getStyle() const = 0;
};
```

### Concrete Products

These classes implement the product interfaces for specific styles, for example:

```cpp
// Modern style products
class ModernChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sitting on a modern minimalist chair";
    }
    
    std::string getStyle() const override {
        return "Modern";
    }
};

// Victorian style products
class VictorianTable : public Table {
public:
    std::string putOn() const override {
        return "Putting items on an elegant Victorian table";
    }
    
    std::string getStyle() const override {
        return "Victorian";
    }
};

// Art Deco style products
class ArtDecoSofa : public Sofa {
public:
    std::string lieOn() const override {
        return "Lying on a bold Art Deco sofa";
    }
    
    std::string getStyle() const override {
        return "Art Deco";
    }
};
```

### The Abstract Factory

This interface declares methods for creating each type of product:

```cpp
class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    virtual std::unique_ptr<Chair> createChair() const = 0;
    virtual std::unique_ptr<Table> createTable() const = 0;
    virtual std::unique_ptr<Sofa> createSofa() const = 0;
};
```

### Concrete Factories

These classes implement the factory methods to create products in a specific style:

```cpp
// Creates Modern style furniture
class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ModernChair>();
    }
    
    std::unique_ptr<Table> createTable() const override {
        return std::make_unique<ModernTable>();
    }
    
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ModernSofa>();
    }
};
```

### Client Code

The client works with factories and products only through their abstract interfaces:

```cpp
void clientCode(const FurnitureFactory& factory) {
    auto chair = factory.createChair();
    auto table = factory.createTable();
    auto sofa = factory.createSofa();
    
    std::cout << "Client: I've got a " << chair->getStyle() << " furniture set." << std::endl;
    std::cout << chair->sitOn() << std::endl;
    std::cout << table->putOn() << std::endl;
    std::cout << sofa->lieOn() << std::endl;
}
```

## Benefits of This Implementation

1. **Consistency**: Products created by the same factory are guaranteed to work together
2. **Isolation**: Concrete product classes are isolated from the client
3. **Flexibility**: It's easy to switch between product families by changing the concrete factory
4. **Single Responsibility Principle**: Product creation logic is isolated in one part of the program
5. **Open/Closed Principle**: You can introduce new variants of products without breaking existing code

## Key Differences from Factory Method Pattern

The Abstract Factory pattern differs from the Factory Method pattern in several important ways:

1. **Factory Method** creates a single product, while **Abstract Factory** creates families of related products
2. **Factory Method** uses inheritance and relies on a subclass to create objects, while **Abstract Factory** uses composition and delegates object creation to a separate factory object
3. **Factory Method** focuses on creating a single object in different ways, while **Abstract Factory** focuses on creating multiple related objects from the same family

## When to Use the Abstract Factory Pattern

Consider using the Abstract Factory pattern when:

1. Your code needs to work with various families of related products
2. You want to ensure that products from the same family are used together
3. You want to provide a library of products where you only reveal their interfaces
4. You need to enforce constraints on product combinations

## Testing the Abstract Factory Pattern

The project includes Google Test cases to verify:

1. That each factory creates products of the correct style
2. That products created by the same factory have a consistent style
3. That different factories create products with different styles and behaviors

These tests ensure that our implementation of the Abstract Factory pattern works as expected.

## Conclusion

The Abstract Factory design pattern provides an elegant solution for creating families of related objects. In our furniture example, it allowed us to create consistent sets of furniture in different styles without coupling the client code to specific product classes. This approach makes it easy to add new furniture styles or types without modifying existing code, demonstrating the power and flexibility of the pattern.

## Building and Running

To build and run the project:

```bash
# Create a build directory
mkdir build && cd build

# Generate build files with CMake
cmake ..

# Build the project
cmake --build .

# Run the main program
./AbstractFactory

# Run the tests
./AbstractFactoryTests
```
