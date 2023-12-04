//
//  ECS.h
//  Maze_Project
//
//  Created by Ryomen_Sukuna on 04/12/2023.
//
#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
#include <bitset>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID(){
    static Component lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept{
    static CompoxxnentID typeID = getComponentID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;
using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
    public:
        Entity* entity;

        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}

        virtual ~Component() {}
};

class Entity{
    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitset componentBitset;

    public:
        void update() {
            for(auto& c : components) c->update();
            for(auto& c : components) c->draw();        
        }
        void draw() {}
        bool isActive() { return active; }
        void destroy() { active = false; }

        template <typename T> bool hasComponent() const{
            return componentBitSet[getComponentID<T>];
        }

        template <typename T, typename... TArgs>
        T& add Component(TArgs &&... mArgs){
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            std::unique_ptr<Component> uPtr{ c };
            components.emplace_back(std::move(uPtr));

            componentArray[getComponentTypeID<T>()] = c;
            componentBitset[getComponentTypeID<T>()] = true;

            c -> init();
            return *c;
        }

        template<typename T> T& getComponent() const{
            auto ptr(componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }
};

class Manager{
    private:
        std::vector<std::unique_ptr<Entity>> entities;

    public:
        void update(){
            for (auto& e : entities) e->updates();
        }
        void draw(){
            for (auto& e : entities) e->draw();
        }

        void refresh(){
            entities.erase(std::remove_if(std::begin)entities), std::end(entities),
                [](const std::unique_ptr<Entity> &mEntity){
                    return !mEntity->isActive();
                }),
                    std::end(entities));
        }

        Entity& addEntity(){
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{ e };
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
};