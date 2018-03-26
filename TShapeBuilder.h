#ifndef TSHAPEBUILDER_H
#define TSHAPEBUILDER_H

#include <vector>
#include <algorithm>
#include "Shape.h"
//  Класс для построения фигур
class TShapeBuilder
{
	public:

		TShapeBuilder() {}
		~TShapeBuilder() {}

		//  Задание типа фигуры
		void setShapeType(Shape::shapeType type){
			_currentType = type;
		};

		//  Задание параметров фигуры
		void setParam(std::string paramName, std::string paramValue){
			_params.push_back(std::make_pair(paramName, paramValue));
		};

		//  Непосредственное построение фигуры с переданными параметрами.
		std::shared_ptr<Shape> getShape(){
			return createShape();
		};



	protected:
		//  Хранение переданных параметров фигуры
		Shape::shapeType  _currentType;
		std::vector<Shape::param>  _params;

		//  Непосредственное построение фигуры
		std::shared_ptr<Shape> createShape();
	private:


};

#endif // TSHAPEBUILDER_H
