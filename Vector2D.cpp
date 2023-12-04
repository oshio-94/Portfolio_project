#include "Vector2D.h"

Vector2D::Vector2D(){
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y){
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::Add(const Vector2D& vec){
    this->x += vec.x;
    this->y += vec.y;
    
    return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec){
    this->x -= vec.x;
    this->y -= vec.y;
    
    return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec){
    this->x *= vec.x;
    this->y *= vec.y;
    
    return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec){
    this->x /= vec.x;
    this->y /= vec.y;
    
    return *this;
}