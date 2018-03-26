#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <string>
#include "Shape.h"
#include "TShapeContainer.h"

/*! Класс для работы с документом
    Обеспечивает работу с настройками документа, агрегирует работу с примитивами
*/

class Document{
	private:
	/*!	Вектор фигур документа*/
	TShapeContainer _shapes;

	/*!	Параметры документа (имя, шрифты и т.д.)*/
	std::string _settings;

	public:
	Document():_settings(""){};
	Document(std::string params):_settings(params){};
	~Document(){};

	std::string getSettings(){return _settings;};
	void setSettings(std::string newSettings){_settings = newSettings;};

	void addShape(std::shared_ptr<Shape> shapeNew){
	    _shapes.addNewShape(shapeNew);
	}

    void removeShape(std::shared_ptr<Shape> shapeRemove){
	    _shapes.removeShape(shapeRemove);
	}

	TShapeContainer shapes() const {return _shapes;}
};

using sharedDocumentPtr = std::shared_ptr<Document>;

#endif
