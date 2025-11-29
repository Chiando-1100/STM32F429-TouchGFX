#ifndef MODEL_HPP
#define MODEL_HPP



class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void setTemperatureSampling(bool enable)
    {
        enableTemperatureSampling = enable;
    }
protected:
    ModelListener* modelListener;
    int tickCount = 0;
    bool enableTemperatureSampling = false;
};

#endif // MODEL_HPP
