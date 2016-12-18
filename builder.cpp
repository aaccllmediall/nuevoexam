#include <iostream>
#include <string>

using namespace std;

/* Final product -- a car */
class Car
{
    public:
        int wheel;
        int engine;
        string body;
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{	
	protected:
		Car *Lambda;
    
	public:
		virtual void createcar() {
			Lambda=new Car;
		} 
        virtual void getWheel();
        virtual void getEngine();
        virtual void getBody();
        virtual void setWheel();
        virtual void setEngine();
        virtual void setBody();
        virtual ~Builder();
};


/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
    public:
        void getWheel()
        {
            Lambda->wheel = 22;
        }

        void getEngine()
        {
            Lambda->engine = 400;
        }

        void getBody()
        {
            Lambda->body = "SUV";
        }
        
        void setWheel()
        {
        	cout << "wheels: " << Lambda->wheel << endl;
        }
        
        void setEngine()
        {
        	cout << "engine: " << Lambda->engine << endl;
        }
        
        void setBody()
        {
        	cout << "body: " << Lambda->body << endl;
        }
        
        ~JeepBuilder()
        {
        	delete Lambda;
        }
};

/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder
{
    public:
        void getWheel()
        {
            Lambda->wheel = 16;
        }

        void getEngine()
        {
            Lambda->engine = 85;
        }

        void getBody()
        {
            Lambda->body = "hatchback";
        }
        
        void setWheel()
        {
        	cout << "wheels: " << Lambda->wheel << endl;
        }
        
        void setEngine()
        {
        	cout << "engine: " << Lambda->engine << endl;
        }
        
        void setBody()
        {
        	cout << "body: " << Lambda->body << endl;
        }
        
        ~NissanBuilder()
        {
        	delete Lambda;
        }
};

/* Director is responsible for the whole process */
class Director
{
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        void getCar()
        {
            builder->getWheel();
            builder->getEngine();
            builder->getBody();
        }
        
        void showCar()
        {
        	builder->setWheel();
        	builder->setEngine();
        	builder->setBody();
        }
        
};

main()
{
    /* A director who controls the process */
    Director director;
    Director director2;

    /* Concrete builders */
    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;

    /* Build a Jeep */
    cout << "Jeep" << endl;
    director.setBuilder(&jeepBuilder); // using JeepBuilder instance
    director.getCar();
    director.showCar();
    jeepBuilder.~JeepBuilder();

    /* Build a Nissan */
    cout << "Nissan" << endl;
    director2.setBuilder(&nissanBuilder); // using NissanBuilder instance
    director2.getCar();
    director2.showCar();
    nissanBuilder.~NissanBuilder();

}
