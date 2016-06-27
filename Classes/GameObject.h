/*
 * Author - Farid
 * Base class for all objects in the scene
 */
#pragma once

#include "cocos2d.h"

class GameObject : public cocos2d::Sprite {
public:
    GameObject();//creates default object with all members set to 0
    //Creates object with defined hitBox and with texture using the name of a SpriteFrame
    GameObject(int width, int height, int x, int y, const std::string &spriteFrameName);
    //Creates object with defined hitBox and with texture using the SpriteFrame
    GameObject(int width, int height, int x, int y, cocos2d::SpriteFrame *spriteFrame);
    cocos2d::Size getSize();
    cocos2d::Vec2 getPosition();
    cocos2d::Rect getHitBox();
    void setSize(int width, int height);
    void setPosition(const cocos2d::Vec2& position);
    void setPosition(int x, int y);
    std::vector<GameObject*> getCollidedObjects(const std::vector<GameObject*> &levelObjects);
    std::vector<std::list<GameObject*>::iterator> getCollidedObjects(std::list<GameObject*> &levelObjects);
    virtual void collide() {}
    virtual void inflictDamage(int damage) {}
    virtual int getDamage () { return 0;}
    ~GameObject();
    
    virtual void setSpeedY(float velocity) {}
    virtual void setSpeedX(float velocity) {}
    virtual short getDirection() { return 0; }
    virtual bool getJumpDuration() { return false; }
    virtual void setJumpDuration(bool set) {}
    virtual bool isFalling() { return false; }

private:
    cocos2d::Rect hitBox;//for collision check
protected:
    void setHitBox(cocos2d::Rect hitbox);
    bool isTransparent;//shows whether the player should be physically affected after collision or not
};