#ifndef TSHAPECONTAINER_H
#define TSHAPECONTAINER_H

#include "Shape.h"

#include <vector>
#include <algorithm>

/*! Контейнер для хранения фигур*/
class TShapeContainer
{
	public:
		TShapeContainer() {};
		~TShapeContainer() {};

		//  Добавление фигуры в контейнер
		void  addNewShape(sharedShapePtr shapeNew){_shapes.push_back(shapeNew);};
		//  Удаление фигуры из контейнера
		void  removeShape(sharedShapePtr shapeRemove){_shapes.erase(std::remove(_shapes.begin(), _shapes.end(), shapeRemove));};

		//  Доступ к итераторам контейнера (для отрисовки)
		auto begin(){return _shapes.begin();}
		auto end(){return _shapes.end();}
	protected:

	private:
		//  Реализация хранения фигур
		std::vector<sharedShapePtr> _shapes;
};

#endif // TSHAPECONTAINER_H
