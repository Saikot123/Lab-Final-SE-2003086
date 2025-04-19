#pragma once

#include <memory>
#include <string>
#include <iostream>

// Abstract Product A - Chair interface
class Chair {
public:
    virtual ~Chair() = default;
    virtual std::string sitOn() const = 0;
    virtual std::string getStyle() const = 0;
};

// Abstract Product B - Table interface
class Table {
public:
    virtual ~Table() = default;
    virtual std::string putOn() const = 0;
    virtual std::string getStyle() const = 0;
};

// Concrete Products - Modern style
class ModernChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sitting on a modern minimalist chair";
    }
    
    std::string getStyle() const override {
        return "Modern";
    }
};

class ModernTable : public Table {
public:
    std::string putOn() const override {
        return "Putting items on a sleek modern table";
    }
    
    std::string getStyle() const override {
        return "Modern";
    }
};


// Concrete Products - Victorian style
class VictorianChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sitting on an ornate Victorian chair";
    }
    
    std::string getStyle() const override {
        return "Victorian";
    }
};

class VictorianTable : public Table {
public:
    std::string putOn() const override {
        return "Putting items on an elegant Victorian table";
    }
    
    std::string getStyle() const override {
        return "Victorian";
    }
};


// Concrete Products - Art Deco style
class ArtDecoChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sitting on a geometric Art Deco chair";
    }
    
    std::string getStyle() const override {
        return "Art Deco";
    }
};

class ArtDecoTable : public Table {
public:
    std::string putOn() const override {
        return "Putting items on a symmetrical Art Deco table";
    }
    
    std::string getStyle() const override {
        return "Art Deco";
    }
};


// Abstract Factory - Furniture factory interface
class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    virtual std::unique_ptr<Chair> createChair() const = 0;
    virtual std::unique_ptr<Table> createTable() const = 0;
    
    // Helper method to show what this factory produces
    void displayProducts() const {
        auto chair = createChair();
        auto table = createTable();
        
        std::cout << "Created " << chair->getStyle() << " furniture set:" << std::endl;
        std::cout << " - Chair: " << chair->sitOn() << std::endl;
        std::cout << " - Table: " << table->putOn() << std::endl;
        std::cout << std::endl;
    }
};

// Concrete Factory 1 - Creates Modern furniture
class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ModernChair>();
    }
    
    std::unique_ptr<Table> createTable() const override {
        return std::make_unique<ModernTable>();
    }
    
};

// Concrete Factory 2 - Creates Victorian furniture
class VictorianFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<VictorianChair>();
    }
    
    std::unique_ptr<Table> createTable() const override {
        return std::make_unique<VictorianTable>();
    }
    
};

// Concrete Factory 3 - Creates Art Deco furniture
class ArtDecoFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ArtDecoChair>();
    }
    
    std::unique_ptr<Table> createTable() const override {
        return std::make_unique<ArtDecoTable>();
    }
    
};
