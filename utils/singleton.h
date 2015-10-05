#ifndef SINGLETON_H
#define SINGLETON_H

template<typename TYPE>
class Singleton
{
public:
    Singleton() {};

    static TYPE& instance()
    {
        static TYPE instance;
        return instance;
    }
private:

    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;

};

#endif
