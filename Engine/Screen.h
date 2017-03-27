//
// Created by Derek on 2/9/2017.
//

#pragma once

#include "Engine.h"
#include "InputController.h"


class Screen : public GameObject {
    friend class Engine;

public:
    Screen(int screenWidth, int screenHeight) : width(screenWidth), height(screenHeight) {
        screen_buffer = al_create_bitmap(screenWidth, screenHeight);
    }

    virtual void Init(InputController* input) override = 0 ;

    virtual void Tick(float delta) override = 0;

    virtual void Destroy() override = 0;

    virtual void Draw() = 0;

    virtual void Resize(int newX, int newY) {
        al_destroy_bitmap(screen_buffer);
        screen_buffer = al_create_bitmap(newX, newY);
    }

protected:
    int width;

    int height;

    ALLEGRO_BITMAP* screen_buffer;
};


