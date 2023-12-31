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
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID getNewComponentTypeID(){
    static ComponentID lastID = 0u;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept{
    static_assert (std::is_base_of<Component, T>::value, "");
    static ComponentID typeID = getNewComponentTypeID();
    return typeID;
}

//Declare max number of components & Groups(render/collision layers)
constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitset = std::bitset<maxComponents>;
using GroupBitset = std::bitset<maxGroups>;
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
        Manager& manager; //Manager reference called manager
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitset componentBitset;
        GroupBitset groupBitset;

    public:
        Entity(Manager& mManager) : manager(mManager) {}
        void update() {
            for(auto& c : components) c->update();   
        }
        void draw() {
            for(auto& c : components) c->draw();
        }
        bool isActive() const { return active; }
        void destroy() { active = false; }

//return true/false if a certain bit is 1 or 0
        bool hasGroup(Group mGroup){
            return groupBitset[mGroup];
        }

//add/remove bit from or to a group
        void addGroup(Group mGroup);
        void delGroup(Group mGroup){
            groupBitset[mGroup] = false;
        }

        template <typename T> bool hasComponent() const
        {
            return componentBitset[getComponentID<T>()];
        }

        template <typename T, typename... TArgs>
            T& addComponent(TArgs&&... mArgs){
                T* c(new T(std::forward<TArgs>(mArgs)...));
                c->entity = this;
                std::unique_ptr<Component> uPtr{ c };
                components.emplace_back(std::move(uPtr));

                componentArray[getComponentID<T>()] = c;
                componentBitset[getComponentID<T>()] = true;

            c -> init();
            return *c;
        }

        template<typename T> T& getComponent() const{
            auto ptr(componentArray[getComponentID<T>()]);
            return *static_cast<T*>(ptr);
        }
};

class Manager{
    private: 
    // vector of entities that Manager looks after
        std::vector<std::unique_ptr<Entity>> entities;
    // array of vectors 
        std::array<std::vector<Entity*>, maxGroups> groupedEntities;

    public:
        void update(){
            for (auto& e : entities) e->update();
        }
        void draw(){
            for (auto& e : entities) e->draw();
        }

        void refresh(){
            for(auto i(0u); i < maxGroups; i++){
                auto& v(groupedEntities[i]);
                v.erase(
                    std::remove_if(std::begin(v), std::end(v), [i](Entity* mEntity)
                    {
                        return !mEntity->isActive() || !mEntity->hasGroup(i);
                    }),
                    std::end(v));
            }

            entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                [](const std::unique_ptr<Entity> &mEntity){
                    return !mEntity->isActive();
                }),
                    std::end(entities));
        }

        void AddToGroup(Entity* mEntity, Group mGroup){
            groupedEntities[mGroup].emplace_back(mEntity);
        }

//get entities as a list
        std::vector<Entity*>& getGroup(Group mGroup){
            return groupedEntities[mGroup];
        }
        Entity& addEntity(){
            Entity* e = new Entity(*this);
            std::unique_ptr<Entity> uPtr{ e };
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
};
