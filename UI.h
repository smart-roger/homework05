#ifndef UI_H
#define UI_H

#include "Controller.h"
#include "Document.h"
#include "Shape.h"
#include "TShapeContainer.h"

#include <memory>
#include <vector>
#include <string>

class TControllerIface;
class Document;

/*! Класс для GUI*/
class UI{

	private:
	//  Текущий контроллер, отображаемый GUI
	TControllerIface*	_controller;

	//  Отрисовка изображения на экране
	void render(const std::shared_ptr<Document> document){
		TShapeContainer _container(document->shapes());
		std::for_each(_container.begin(), _container.end(), [](auto shape){shape->draw();});
	};

	public:
	UI(): _controller(nullptr){};
	UI(const UI& other) = delete;
	const UI& operator=(const UI& other) = delete;

	UI(const UI&& other) = delete;
	const UI& operator=(UI&& other) = delete;
	~UI(){};

	//- создание нового документа
	void createDoc(std::string settings);

	//- импорт документа из файла
	void importDoc(std::string fileFrom);

	//- экспорт документа в файл
	void exportDoc(std::string fileTo);

	//- создание графического примитива
	void shapeCreate(Shape::shapeType type, std::vector<Shape::param> params);

	//- удаление графического примитива
	void shapeRemove(std::shared_ptr<Shape> shapeRemove);

	/*!	Отображение основного окна*/
	void show(){};

	/*!	Обновление содержимого окна (рендеринг)*/
	void update();

	/*! Связывание GUI с контроллером*/
	void setController(TControllerIface* newController){
		_controller=newController;
	}
};

#endif
