#include <iostream>

// Abstract state
class TrafficLights
{
public:
    virtual void handle() = 0;
};

class RedState : public TrafficLights
{
public:
    void handle() override
    {
        std::cout << "In Red state now" << std::endl;
    }
};

class YellowState : public TrafficLights
{
public:
    void handle() override
    {
        std::cout << "In Yellow state now" << std::endl;
    }
};
class GreenState : public TrafficLights
{
public:
    void handle() override
    {
        std::cout << "In Green state now" << std::endl;
    }
};

class Context
{
    TrafficLights *current_state_;

public:
    void switchState(TrafficLights *state)
    {
        this->current_state_ = state;
    }
};