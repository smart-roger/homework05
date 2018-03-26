#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include <iostream>

class Shape{
/*!
Базовый класс для иерархии фигур. Интерфейс для работы с фигурами.
*/

	public:
	    //  Типы поддерживаемых фигур
    enum class shapeType{
        Line,
        Polygon,
        Circle
    };

    //  Тип для передачи параметров фигуры
    using param = std::pair<std::string, std::string>;

    //enum class

	Shape(){};
	virtual ~Shape(){};

	virtual void draw()=0;
	virtual void setParam(std::string param, std::string value)=0;
};

//  Реализация графических примитивов с заданным интерфейсом.

class Line : public Shape{
    virtual void draw() override {std::cout << "draw line" << std::endl;}
    virtual void setParam(std::string param, std::string value) override {std::cout << "Line: " << param<<"\t"<<value<<std::endl;}
};

class Polygon : public Shape{
    virtual void draw() override {std::cout << "draw polygon" << std::endl;}
    virtual void setParam(std::string param, std::string value) override {std::cout << "Polygon: " << param<<"\t"<<value<<std::endl;}
};

class Circle : public Shape{
    virtual void draw() override {std::cout << "draw circle" << std::endl;}
    virtual void setParam(std::string param, std::string value) override {std::cout << "Circle: " << param<<"\t"<<value<<std::endl;}
};

using uniqShapePtr = std::unique_ptr<Shape>;
using sharedShapePtr = std::shared_ptr<Shape>;

#endif // SHAPE_H
